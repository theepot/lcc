#include "esc64.i.h"

static void progend(void)
{
}

static void progbeg(int argc, char *argv[])
{
	int i;

	{
		union { char c; int i; } u;
		u.i = 0;
		u.c = 1;
		swap = ((int)(u.i == 1)) != IR->little_endian;
	}

	parseflags(argc, argv);

	for(i = 0; i < 4; ++i)
	{
		ireg[i] = mkreg("r%d", i, 1, IREG);
	}
//	reg5 = mkreg("r5", 5, 1, IREG);
//	regsp = mkreg("sp", 6, 1, IREG);
//	regpc = mkreg("pc", 7, 1, IREG);

	iregw = mkwildcard(ireg);

	tmask[IREG] = TREG_MASK;
	vmask[IREG] = 0;
	tmask[FREG] = 0;
	vmask[FREG] = 0;

	print(";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	print(";; ESC64 assembly generated by LCC 4.2 ;;\n");
	print(";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n\n");

	cur_seg = -1;
}

static Symbol rmap(int opk)
{
	switch (optype(opk))
	{
		case I:
		case U:
		case P:
		case B:
			return iregw;
		case F:
			assert(0 && "rmap(): case F");
			return 0;
		default:
			return 0;
	}
}

static void target(Node p)
{
	assert(p);

	switch (specific(p->op))
	{
	case CALL+I:
	case CALL+U:
	case CALL+P: //case CALL+V:
		setreg(p, ireg[0]); //return value is in r0
		break;

	case RET+I:
	case RET+U:
	case RET+P:
		rtarget(p, 0, ireg[0]); //always return in r0
		break;

	case CVI+I:
		if(opsize(p->op) == 2)
		{
			assert(opsize(p->kids[0]->op) == 1 && "target(): CVI+I");
			rtarget(p, 0, ireg[0]);
			setreg(p, ireg[0]);
		}
		break;

	case ASGN+B:
		rtarget(p, 0, ireg[0]);
		rtarget(p->kids[1], 0, ireg[1]);
		break;

	case DIV+I:
	case DIV+U:
	case MOD+I:
	case MOD+U:
	case MUL+I:
	case MUL+U:
		assert(opsize(p->op) == 2 && "target(): div/mod/mul opsize != 2");
		rtarget(p, 0, ireg[0]);
		rtarget(p, 1, ireg[1]);
		break;

	default:
		break;
	}
}

static void clobber(Node p)
{
	assert(p);

	switch (specific(p->op))
	{
	case ASGN+B:
		spill(2, IREG, p);
		break;
//	case CALL + I:
//	case CALL + P:
//	case CALL + U:
//		spill(TREG_MASK & ~1, IREG, p); //dont spill r0 (return reg)
//		break;
//	case CALL + V:
//		spill(TREG_MASK, IREG, p);
//		break;
	}
}

static void emit2(Node p)
{
	switch(specific(p->op))
	{
	case LABEL+V:
		assert(p->syms[0]);
		if(p->syms[0]->sclass != STATIC && !p->syms[0]->generated)	{ print(".global "); }
		print("%s:\n", p->syms[0]->x.name);
		break;

//	case CVU+I:
//		if(opsize(p->op) == 2)
//		{
//			switch(opsize(p->kids[0]->op))
//			{
//			case 1:	//U1 -> I2
//				print("\tmov\t\tr6, 0xFF\n");
//				print("\tand\t\t%s, %s, r6\n",
//					p->syms[RX]->x.name,
//					p->kids[0]->syms[RX]->x.name);
//				break;
//
//			case 2:	//U2 -> I2
//				print("\tmov\t\t%s, %s\n",
//					p->syms[RX]->x.name,
//					p->kids[0]->syms[RX]->x.name);
//				break;
//			}
//		}
//		break;
//
//	case CVI+U:
//		if(opsize(p->op) == 2 && opsize(p->kids[0]->op) == 1)
//		{
//			//U1 -> I2
//
//		}
//		break;
	}
}

static void doarg(Node p)
{
	assert(p && p->syms[0]);
	mkactual(2, p->syms[0]->u.c.v.i);
}

static void local(Symbol p)
{
	if(askregvar(p, rmap(ttob(p->type))) == 0)
	{
		mkauto(p);
	}
}

/**
 *	CALL FRAME:
 *		|					|	high addresses
 *		| caller frame		|
 *		|-------------------|
 *		| incomming args	|	-12
 *		|-------------------|
 *		| return addr		|	-10
 *		|-------------------|
 *		| saved regs		|	-8
 *		| (r0-r4)			|	 0		<-- frame pointer (r4)
 *		|-------------------|
 *		| locals + temps	|	+localoffset
 *		|-------------------|
 *		| callee frame		|
 *		|					|	low addresses
 */
static void function(Symbol f, Symbol caller[], Symbol callee[], int ncalls)
{
	int i;

	//function start
	if(f->sclass != STATIC)
	{
		print(".global ");
	}
	print("%s:\n", f->x.name);

	//save temps + frame pointer, set up frame pointer
	print(
		"\tpush\tr0\n"
		"\tpush\tr1\n"
		"\tpush\tr2\n"
		"\tpush\tr3\n"
		"\tpush\tr4\n"
		"\tmov\t\tr4, sp\n\n");

	//arguments
	usedmask[0] = usedmask[1] = 0;
	freemask[0] = freemask[1] = ~(unsigned)0;
	offset = 12; //saved registers + return address

	for (i = 0; callee[i]; i++)
	{
		Symbol p = callee[i];
		Symbol q = caller[i];
		assert(q);
		p->x.offset = q->x.offset = offset;
		p->x.name = q->x.name = stringf("%d", p->x.offset);
		p->sclass = q->sclass = AUTO;
		offset += roundup(q->type->size, 2);
	}
	assert(caller[i] == 0);
	offset = maxoffset = 0;

	//generate code
	gencode(caller, callee);

	//allocate space in frame
	framesize = roundup(maxoffset, 2);
	if(framesize > 0)
	{
		print(
			"\tmov\t\tr5, %d\n"
			"\tsub\t\tsp, sp, r5\t\t;allocate space for locals\n",
			framesize);
	}

	//emit code
	emitcode();

	//restore sp, frame pointer and temps
	print(
		"\n"
		"\tmov\t\tsp, r4\n"
		"\tpop\t\tr4\n"
		"\tpop\t\tr3\n"
		"\tpop\t\tr2\n"
		"\tpop\t\tr1\n"
		"\tpop\t\tr0\n");

	//return
	print("\tret\n");

	print(";;end %s\n\n", f->x.name);
}

static void defconst(int suffix, int size, Value v)
{
	switch(suffix)
	{
	case F:
		assert(0 && "defconst(): no floating point support");
		break;

	case I:
	case U:
		switch(size)
		{
		case 1:
			print(".byte\t0x%X\n", (unsigned)(unsigned char)(suffix == I ? v.i : v.u));
			break;

		case 2:
			print(".word\t0x%X\n", (unsigned)(unsigned short)(suffix == I ? v.i : v.u));
			break;

		case 4:
			assert(0 && "defconst(): no int32 support");
			break;

		default:
			assert(0 && "defconst(): I or U with size != 1, 2 or 4");
			break;
		}
		break;

	case P:
		assert(size == 2 && "defconst(): case P: size != 2");
		print(".word\t0x%X\n", (unsigned)v.p);
		break;

	default:
		assert(0 && "defconst(): unknown suffix");
		break;
	}
}

static void defaddress(Symbol p)
{
	print(".word\t%s\n", p->x.name);
}

static void defstring(int n, char *str)
{
	char *s;
	for (s = str; s < str + n; ++s)
	{
		print(".byte %d\n", (*s) & 0xFF);
	}
}

static void export(Symbol p)
{
}

static void import(Symbol p)
{
}

static void defsymbol(Symbol p)
{
	if(p->scope >= LOCAL && p->sclass == STATIC)
	{
		p->x.name = stringf("__L%d", genlabel(1));
	}
	else if (p->generated)
	{
		p->x.name = stringf("__L%s", p->name);
	}
	else
	{
		assert(p->scope != CONSTANTS || isint(p->type) || isptr(p->type)); //what's this for?
		p->x.name = p->name;
	}
}

static void address(Symbol q, Symbol p, long n)
{
	fprint(stderr, "address(): q=%s is at p->x.offset(%d) + n(%d)\n", p->x.name, p->x.offset, n);

	if (p->scope == GLOBAL || p->sclass == STATIC || p->sclass == EXTERN)
	{
		q->x.name = stringf("%s%s%D", p->x.name, n >= 0 ? "+" : "", n);
	}
	else
	{
		assert(n <= INT_MAX && n >= INT_MIN);
		q->x.offset = p->x.offset + n;
		q->x.name = stringd(q->x.offset);
	}
}

static void global(Symbol p)
{
	print(".pad\t%d\n", p->type->align);
	print(".global %s:\n");
}

static void segment(int n)
{
	switch(n)
	{
	case CODE:
	case DATA:
	case LIT:
		if(cur_seg == CODE || cur_seg == DATA || cur_seg == LIT) { return; }
		print(".data\n");
		print(".align 2\n");
		break;
	case BSS:
		if(cur_seg == BSS) { return; }
		print(".bss\n");
		print(".align 2\n");
		break;
	default:
		assert(0 && "segment(): unknown segment");
		break;
	}

	cur_seg = n;
}

static void space(int n)
{
	if(cseg != BSS)
	{
		print(".resb\t%d\n", n);
	}
}

static void blkloop(int dreg, int doff, int sreg, int soff, int size, int tmps[])
{
	assert(0 && "blkloop(): should never be called");
}

static void blkfetch(int size, int off, int reg, int tmp)
{
	assert(0 && "blkfetch(): should never be called");
}

static void blkstore(int size, int off, int reg, int tmp)
{
	assert(0 && "blkstore(): should never be called");
}

Interface esc64IR =
{
	/* type metrics
	size, align, outofline */
	1, 1, 0, /* char */
	2, 2, 0, /* short */
	2, 2, 0, /* int */
	2, 2, 0, /* long */
	2, 2, 0, /* long long */
	4, 4, 1, /* float */
	8, 8, 1, /* double */
	8, 8, 1, /* long double */
	2, 2, 0, /* T* */
	0, 1, 0, /* struct */

	1, /* little_endian */
	0, /* mulops_calls */
	0, /* wants_callb */
	0, /* wants_argb */
	1, /* left_to_right */
	0, /* wants_dag */
	0, /* unsigned_char */

	/* routines */
	address, blockbeg, blockend, defaddress, defconst, defstring, defsymbol, emit,
	export, function, gen, global, import, local, progbeg, progend, segment,
	space,
	0, 0, 0, 0, 0, 0, 0, /* stabX routines */

	/* Xinterface */
	{
		1, /* max_unaligned_load */
		/* BURM routines */
		rmap, blkfetch, blkstore, blkloop, _label, _rule, _nts, _kids, _string,
		_templates, _isinstruction, _ntname, emit2, doarg, target,
		clobber,
	}
};

static char rcsid[] = "$Id$";
