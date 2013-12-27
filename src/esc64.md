%{
#include "esc64.i.h"
%}
%start stmt
%term CNSTF4=4113
%term CNSTF8=8209
%term CNSTF16=16401
%term CNSTI1=1045
%term CNSTI2=2069
%term CNSTI4=4117
%term CNSTI8=8213
%term CNSTP4=4119
%term CNSTP8=8215
%term CNSTU1=1046
%term CNSTU2=2070
%term CNSTU4=4118
%term CNSTU8=8214
 
%term ARGB=41
%term ARGF4=4129
%term ARGF8=8225
%term ARGF16=16417
%term ARGI4=4133
%term ARGI8=8229
%term ARGP4=4135
%term ARGP8=8231
%term ARGU4=4134
%term ARGU8=8230

%term ASGNB=57
%term ASGNF4=4145
%term ASGNF8=8241
%term ASGNF16=16433
%term ASGNI1=1077
%term ASGNI2=2101
%term ASGNI4=4149
%term ASGNI8=8245
%term ASGNP4=4151
%term ASGNP8=8247
%term ASGNU1=1078
%term ASGNU2=2102
%term ASGNU4=4150
%term ASGNU8=8246

%term INDIRB=73
%term INDIRF4=4161
%term INDIRF8=8257
%term INDIRF16=16449
%term INDIRI1=1093
%term INDIRI2=2117
%term INDIRI4=4165
%term INDIRI8=8261
%term INDIRP4=4167
%term INDIRP8=8263
%term INDIRU1=1094
%term INDIRU2=2118
%term INDIRU4=4166
%term INDIRU8=8262

%term CVFF4=4209
%term CVFF8=8305
%term CVFF16=16497
%term CVFI4=4213
%term CVFI8=8309

%term CVIF4=4225
%term CVIF8=8321
%term CVIF16=16513
%term CVII1=1157
%term CVII2=2181
%term CVII4=4229
%term CVII8=8325
%term CVIU1=1158
%term CVIU2=2182
%term CVIU4=4230
%term CVIU8=8326

%term CVPP4=4247
%term CVPP8=8343
%term CVPP16=16535
%term CVPU4=4246
%term CVPU8=8342

%term CVUI1=1205
%term CVUI2=2229
%term CVUI4=4277
%term CVUI8=8373
%term CVUP4=4279
%term CVUP8=8375
%term CVUP16=16567
%term CVUU1=1206
%term CVUU2=2230
%term CVUU4=4278
%term CVUU8=8374

%term NEGF4=4289
%term NEGF8=8385
%term NEGF16=16577
%term NEGI4=4293
%term NEGI8=8389

%term CALLB=217
%term CALLF4=4305
%term CALLF8=8401
%term CALLF16=16593
%term CALLI4=4309
%term CALLI8=8405
%term CALLP4=4311
%term CALLP8=8407
%term CALLU4=4310
%term CALLU8=8406
%term CALLV=216

%term RETF4=4337
%term RETF8=8433
%term RETF16=16625
%term RETI4=4341
%term RETI8=8437
%term RETP4=4343
%term RETP8=8439
%term RETU4=4342
%term RETU8=8438
%term RETV=248

%term ADDRGP4=4359
%term ADDRGP8=8455

%term ADDRFP4=4375
%term ADDRFP8=8471

%term ADDRLP4=4391
%term ADDRLP8=8487

%term ADDF4=4401
%term ADDF8=8497
%term ADDF16=16689
%term ADDI4=4405
%term ADDI8=8501
%term ADDP4=4407
%term ADDP8=8503
%term ADDU4=4406
%term ADDU8=8502

%term SUBF4=4417
%term SUBF8=8513
%term SUBF16=16705
%term SUBI4=4421
%term SUBI8=8517
%term SUBP4=4423
%term SUBP8=8519
%term SUBU4=4422
%term SUBU8=8518

%term LSHI4=4437
%term LSHI8=8533
%term LSHU4=4438
%term LSHU8=8534

%term MODI4=4453
%term MODI8=8549
%term MODU4=4454
%term MODU8=8550

%term RSHI4=4469
%term RSHI8=8565
%term RSHU4=4470
%term RSHU8=8566

%term BANDI4=4485
%term BANDI8=8581
%term BANDU4=4486
%term BANDU8=8582

%term BCOMI4=4501
%term BCOMI8=8597
%term BCOMU4=4502
%term BCOMU8=8598

%term BORI4=4517
%term BORI8=8613
%term BORU4=4518
%term BORU8=8614

%term BXORI4=4533
%term BXORI8=8629
%term BXORU4=4534
%term BXORU8=8630

%term DIVF4=4545
%term DIVF8=8641
%term DIVF16=16833
%term DIVI4=4549
%term DIVI8=8645
%term DIVU4=4550
%term DIVU8=8646

%term MULF4=4561
%term MULF8=8657
%term MULF16=16849
%term MULI4=4565
%term MULI8=8661
%term MULU4=4566
%term MULU8=8662

%term EQF4=4577
%term EQF8=8673
%term EQF16=16865
%term EQI4=4581
%term EQI8=8677
%term EQU4=4582
%term EQU8=8678

%term GEF4=4593
%term GEF8=8689
%term GEI4=4597
%term GEI8=8693
%term GEI16=16885
%term GEU4=4598
%term GEU8=8694

%term GTF4=4609
%term GTF8=8705
%term GTF16=16897
%term GTI4=4613
%term GTI8=8709
%term GTU4=4614
%term GTU8=8710

%term LEF4=4625
%term LEF8=8721
%term LEF16=16913
%term LEI4=4629
%term LEI8=8725
%term LEU4=4630
%term LEU8=8726

%term LTF4=4641
%term LTF8=8737
%term LTF16=16929
%term LTI4=4645
%term LTI8=8741
%term LTU4=4646
%term LTU8=8742

%term NEF4=4657
%term NEF8=8753
%term NEF16=16945
%term NEI4=4661
%term NEI8=8757
%term NEU4=4662
%term NEU8=8758

%term JUMPV=584

%term LABELV=600

%term LOADB=233
%term LOADF4=4321
%term LOADF8=8417
%term LOADF16=16609
%term LOADI1=1253
%term LOADI2=2277
%term LOADI4=4325
%term LOADI8=8421
%term LOADP4=4327
%term LOADP8=8423
%term LOADU1=1254
%term LOADU2=2278
%term LOADU4=4326
%term LOADU8=8422

%term VREGP=711
%%
reg:  INDIRI1(VREGP)     "# read register\n"
reg:  INDIRU1(VREGP)     "# read register\n"

reg:  INDIRI2(VREGP)     "# read register\n"
reg:  INDIRU2(VREGP)     "# read register\n"

reg:  INDIRF4(VREGP)     "# read register\n"
reg:  INDIRI4(VREGP)     "# read register\n"
reg:  INDIRP4(VREGP)     "# read register\n"
reg:  INDIRU4(VREGP)     "# read register\n"

reg:  INDIRF8(VREGP)     "# read register\n"
reg:  INDIRI8(VREGP)     "# read register\n"
reg:  INDIRP8(VREGP)     "# read register\n"
reg:  INDIRU8(VREGP)     "# read register\n"

stmt: ASGNI1(VREGP,reg)  "# write register\n"
stmt: ASGNU1(VREGP,reg)  "# write register\n"

stmt: ASGNI2(VREGP,reg)  "# write register\n"
stmt: ASGNU2(VREGP,reg)  "# write register\n"

stmt: ASGNF4(VREGP,reg)  "# write register\n"
stmt: ASGNI4(VREGP,reg)  "# write register\n"
stmt: ASGNP4(VREGP,reg)  "# write register\n"
stmt: ASGNU4(VREGP,reg)  "# write register\n"

stmt: ASGNF8(VREGP,reg)  "# write register\n"
stmt: ASGNI8(VREGP,reg)  "# write register\n"
stmt: ASGNP8(VREGP,reg)  "# write register\n"
stmt: ASGNU8(VREGP,reg)  "# write register\n"
con: CNSTI1  "%a"
con: CNSTU1  "%a"

con: CNSTI2  "%a"
con: CNSTU2  "%a"

con: CNSTI4  "%a"
con: CNSTU4  "%a"
con: CNSTP4  "%a"

con: CNSTI8  "%a"
con: CNSTU8  "%a"
con: CNSTP8  "%a"
stmt: reg  ""
reg: ADDRGP4  "set %a,%%%c\n"  1
stk13: ADDRFP4  "%a"                  imm(a)
stk13: ADDRLP4  "%a"                  imm(a)
reg:   stk13   "add %0,%%fp,%%%c\n"  1
stk: ADDRFP4  "set %a,%%%c\n"                      2
stk: ADDRLP4  "set %a,%%%c\n"                      2
reg: ADDRFP4  "set %a,%%%c\nadd %%%c,%%fp,%%%c\n"  3
reg: ADDRLP4  "set %a,%%%c\nadd %%%c,%%fp,%%%c\n"  3
con13: CNSTI1  "%a"  imm(a)
con13: CNSTI2  "%a"  imm(a)
con13: CNSTI4  "%a"  imm(a)
con13: CNSTU1  "%a"  imm(a)
con13: CNSTU2  "%a"  imm(a)
con13: CNSTU4  "%a"  imm(a)
con13: CNSTP4  "%a"  imm(a)
base: ADDI4(reg,con13)  "%%%0+%1"
base: ADDP4(reg,con13)  "%%%0+%1"
base: ADDU4(reg,con13)  "%%%0+%1"
base: reg    "%%%0"
base: con13  "%0"
base: stk13  "%%fp+%0"
addr: base           "%0"
addr: ADDI4(reg,reg)  "%%%0+%%%1"
addr: ADDP4(reg,reg)  "%%%0+%%%1"
addr: ADDU4(reg,reg)  "%%%0+%%%1"
addr: stk            "%%fp+%%%0"
reg:  INDIRI1(addr)     "ldsb [%0],%%%c\n"  1
reg:  INDIRI2(addr)     "ldsh [%0],%%%c\n"  1
reg:  INDIRI4(addr)     "ld [%0],%%%c\n"    1
reg:  INDIRU1(addr)     "ldub [%0],%%%c\n"  1
reg:  INDIRU2(addr)     "lduh [%0],%%%c\n"  1
reg:  INDIRU4(addr)     "ld [%0],%%%c\n"    1
reg:  INDIRP4(addr)     "ld [%0],%%%c\n"    1
reg:  INDIRF4(addr)     "ld [%0],%%f%c\n"   1
stmt: ASGNI1(addr,reg)  "stb %%%1,[%0]\n"   1
stmt: ASGNI2(addr,reg)  "sth %%%1,[%0]\n"   1
stmt: ASGNI4(addr,reg)  "st %%%1,[%0]\n"    1
stmt: ASGNU1(addr,reg)  "stb %%%1,[%0]\n"   1
stmt: ASGNU2(addr,reg)  "sth %%%1,[%0]\n"   1
stmt: ASGNU4(addr,reg)  "st %%%1,[%0]\n"    1
stmt: ASGNP4(addr,reg)  "st %%%1,[%0]\n"    1
stmt: ASGNF4(addr,reg)  "st %%f%1,[%0]\n"   1
addrl: ADDRLP4            "%%%fp+%a"          imm(a)

reg:   INDIRF8(addrl)     "ldd [%0],%%f%c\n"  1
stmt:  ASGNF8(addrl,reg)  "std %%f%1,[%0]\n"  1
reg:  INDIRF8(base)     "# ld2 [%0],%%f%c\n"  2
stmt: ASGNF8(base,reg)  "# st2 %%f%1,[%0]\n"  2
spill:  ADDRLP4          "%a" !imm(a)

stmt: ASGNI1(spill,reg)  "set %0,%%g1\nstb %%%1,[%%fp+%%g1]\n"
stmt: ASGNI2(spill,reg)  "set %0,%%g1\nsth %%%1,[%%fp+%%g1]\n"
stmt: ASGNI4(spill,reg)  "set %0,%%g1\nst %%%1,[%%fp+%%g1]\n"
stmt: ASGNU1(spill,reg)  "set %0,%%g1\nstb %%%1,[%%fp+%%g1]\n"
stmt: ASGNU2(spill,reg)  "set %0,%%g1\nsth %%%1,[%%fp+%%g1]\n"
stmt: ASGNU4(spill,reg)  "set %0,%%g1\nst %%%1,[%%fp+%%g1]\n"
stmt: ASGNP4(spill,reg)  "set %0,%%g1\nst %%%1,[%%fp+%%g1]\n"
stmt: ASGNF4(spill,reg)  "set %0,%%g1\nst %%f%1,[%%fp+%%g1]\n"
stmt: ASGNF8(spill,reg)  "set %0,%%g1\nstd %%f%1,[%%fp+%%g1]\n"
reg: CVII4(INDIRI1(addr))  "ldsb [%0],%%%c\n"  1
reg: CVII4(INDIRI2(addr))  "ldsh [%0],%%%c\n"  1
reg: CVUU4(INDIRU1(addr))  "ldub [%0],%%%c\n"  1
reg: CVUU4(INDIRU2(addr))  "lduh [%0],%%%c\n"  1
reg: CVUI4(INDIRU1(addr))  "ldub [%0],%%%c\n"  1
reg: CVUI4(INDIRU2(addr))  "lduh [%0],%%%c\n"  1
reg: LOADI1(reg)  "mov %%%0,%%%c\n"  move(a)
reg: LOADI2(reg)  "mov %%%0,%%%c\n"  move(a)
reg: LOADI4(reg)  "mov %%%0,%%%c\n"  move(a)
reg: LOADP4(reg)  "mov %%%0,%%%c\n"  move(a)
reg: LOADU1(reg)  "mov %%%0,%%%c\n"  move(a)
reg: LOADU2(reg)  "mov %%%0,%%%c\n"  move(a)
reg: LOADU4(reg)  "mov %%%0,%%%c\n"  move(a)
reg: CNSTI1  "# reg\n"  range(a, 0, 0)
reg: CNSTI2  "# reg\n"  range(a, 0, 0)
reg: CNSTI4  "# reg\n"  range(a, 0, 0)
reg: CNSTP4  "# reg\n"  range(a, 0, 0)
reg: CNSTU1  "# reg\n"  range(a, 0, 0)
reg: CNSTU2  "# reg\n"  range(a, 0, 0)
reg: CNSTU4  "# reg\n"  range(a, 0, 0)
reg: con  "set %0,%%%c\n"  1
rc: con13  "%0"
rc: reg    "%%%0"
reg: ADDI4(reg,rc)   "add %%%0,%1,%%%c\n"  1
reg: ADDP4(reg,rc)   "add %%%0,%1,%%%c\n"  1
reg: ADDU4(reg,rc)   "add %%%0,%1,%%%c\n"  1
reg: BANDI4(reg,rc)  "and %%%0,%1,%%%c\n"  1
reg: BORI4(reg,rc)   "or %%%0,%1,%%%c\n"   1
reg: BXORI4(reg,rc)  "xor %%%0,%1,%%%c\n"  1
reg: BANDU4(reg,rc)  "and %%%0,%1,%%%c\n"  1
reg: BORU4(reg,rc)   "or %%%0,%1,%%%c\n"   1
reg: BXORU4(reg,rc)  "xor %%%0,%1,%%%c\n"  1
reg: SUBI4(reg,rc)   "sub %%%0,%1,%%%c\n"  1
reg: SUBP4(reg,rc)   "sub %%%0,%1,%%%c\n"  1
reg: SUBU4(reg,rc)   "sub %%%0,%1,%%%c\n"  1
rc5: CNSTI4  "%a"    range(a, 0, 31)
rc5: reg    "%%%0"
reg: LSHI4(reg,rc5)  "sll %%%0,%1,%%%c\n"  1
reg: LSHU4(reg,rc5)  "sll %%%0,%1,%%%c\n"  1
reg: RSHI4(reg,rc5)  "sra %%%0,%1,%%%c\n"  1
reg: RSHU4(reg,rc5)  "srl %%%0,%1,%%%c\n"  1
reg: BANDI4(reg,BCOMI4(rc))  "andn %%%0,%1,%%%c\n"  1
reg: BORI4(reg,BCOMI4(rc))   "orn %%%0,%1,%%%c\n"   1
reg: BXORI4(reg,BCOMI4(rc))  "xnor %%%0,%1,%%%c\n"  1
reg: BANDU4(reg,BCOMU4(rc))  "andn %%%0,%1,%%%c\n"  1
reg: BORU4(reg,BCOMU4(rc))   "orn %%%0,%1,%%%c\n"   1
reg: BXORU4(reg,BCOMU4(rc))  "xnor %%%0,%1,%%%c\n"  1
reg: NEGI4(reg)   "neg %%%0,%%%c\n"  1
reg: BCOMI4(reg)  "not %%%0,%%%c\n"  1
reg: BCOMU4(reg)  "not %%%0,%%%c\n"  1
reg: CVII4(reg)  "sll %%%0,8*(4-%a),%%%c; sra %%%c,8*(4-%a),%%%c\n"  2
reg: CVUU4(reg)  "sll %%%0,8*(4-%a),%%%c; srl %%%c,8*(4-%a),%%%c\n"  2
reg: CVUU4(reg)  "and %%%0,0xff,%%%c\n" (a->syms[0]->u.c.v.i == 1 ? 1 : LBURG_MAX)
reg: CVUU4(reg)  "set 0xffff,%%g1; and %%%0,%%g1,%%%c\n"  2
reg: CVUI4(reg)  "and %%%0,0xff,%%%c\n" (a->syms[0]->u.c.v.i == 1 ? 1 : LBURG_MAX)
reg: CVUI4(reg)  "set 0xffff,%%g1; and %%%0,%%g1,%%%c\n"  2
addrg: ADDRGP4        "%a"
stmt:  JUMPV(addrg)  "ba %0; nop\n"   2
stmt:  JUMPV(addr)   "jmp %0; nop\n"  2
stmt:  LABELV        "%a:\n"
stmt: EQI4(reg,rc)  "cmp %%%0,%1; be %a; nop\n"    3
stmt: EQU4(reg,rc)  "cmp %%%0,%1; be %a; nop\n"    3
stmt: GEI4(reg,rc)  "cmp %%%0,%1; bge %a; nop\n"   3
stmt: GEU4(reg,rc)  "cmp %%%0,%1; bgeu %a; nop\n"  3
stmt: GTI4(reg,rc)  "cmp %%%0,%1; bg %a; nop\n"    3
stmt: GTU4(reg,rc)  "cmp %%%0,%1; bgu %a; nop\n"   3
stmt: LEI4(reg,rc)  "cmp %%%0,%1; ble %a; nop\n"   3
stmt: LEU4(reg,rc)  "cmp %%%0,%1; bleu %a; nop\n"  3
stmt: LTI4(reg,rc)  "cmp %%%0,%1; bl %a; nop\n"    3
stmt: LTU4(reg,rc)  "cmp %%%0,%1; blu %a; nop\n"   3
stmt: NEI4(reg,rc)  "cmp %%%0,%1; bne %a; nop\n"   3
stmt: NEU4(reg,rc)  "cmp %%%0,%1; bne %a; nop\n"   3
call: ADDRGP4           "%a"
call: addr             "%0"
reg:  CALLF8(call)      "call %0; nop\n"                2
reg:  CALLF4(call)      "call %0; nop\n"                2
reg:  CALLI4(call)      "call %0; nop\n"                2
reg:  CALLP4(call)      "call %0; nop\n"                2
reg:  CALLU4(call)      "call %0; nop\n"                2
stmt: CALLV(call)       "call %0; nop\n"                2
stmt: CALLB(call,reg)   "call %0; st %%%1,[%%sp+64]; unimp %b&0xfff\n"  3

stmt: RETF8(reg)  "# ret\n"  1
stmt: RETF4(reg)  "# ret\n"  1
stmt: RETI4(reg)  "# ret\n"  1
stmt: RETU4(reg)  "# ret\n"  1
stmt: RETP4(reg)  "# ret\n"  1
stmt: ARGI4(reg)  "st %%%0,[%%sp+4*%c+68]\n"  1
stmt: ARGU4(reg)  "st %%%0,[%%sp+4*%c+68]\n"  1
stmt: ARGP4(reg)  "st %%%0,[%%sp+4*%c+68]\n"  1
stmt: ARGF4(reg)  "# ARGF4\n"  1
stmt: ARGF8(reg)  "# ARGF8\n"  1

reg: DIVI4(reg,rc)   "sra %%%0,31,%%g1; wr %%g0,%%g1,%%y; nop; nop; nop; sdiv %%%0,%1,%%%c\n"       6

reg: DIVU4(reg,rc)   "wr %%g0,%%g0,%%y; nop; nop; nop; udiv %%%0,%1,%%%c\n"       5

reg: MODI4(reg,rc)   "sra %%%0,31,%%g1; wr %%g0,%%g1,%%y; nop; nop; nop; sdiv %%%0,%1,%%g1\n; smul %%g1,%1,%%g1; sub %%%0,%%g1,%%%c\n"  8


reg: MODU4(reg,rc)   "wr %%g0,%%g0,%%y; nop; nop; nop; udiv %%%0,%1,%%g1\n; umul %%g1,%1,%%g1; sub %%%0,%%g1,%%%c\n"  7


reg: MULI4(rc,reg)   "smul %%%1,%0,%%%c\n"  1
reg: MULU4(rc,reg)   "umul %%%1,%0,%%%c\n"  1
reg: ADDF8(reg,reg)  "faddd %%f%0,%%f%1,%%f%c\n"  1
reg: ADDF4(reg,reg)  "fadds %%f%0,%%f%1,%%f%c\n"  1
reg: DIVF8(reg,reg)  "fdivd %%f%0,%%f%1,%%f%c\n"  1
reg: DIVF4(reg,reg)  "fdivs %%f%0,%%f%1,%%f%c\n"  1
reg: MULF8(reg,reg)  "fmuld %%f%0,%%f%1,%%f%c\n"  1
reg: MULF4(reg,reg)  "fmuls %%f%0,%%f%1,%%f%c\n"  1
reg: SUBF8(reg,reg)  "fsubd %%f%0,%%f%1,%%f%c\n"  1
reg: SUBF4(reg,reg)  "fsubs %%f%0,%%f%1,%%f%c\n"  1
reg: NEGF4(reg)   "fnegs %%f%0,%%f%c\n"  1
reg: LOADF4(reg)  "fmovs %%f%0,%%f%c\n"  1
reg: CVFF4(reg)   "fdtos %%f%0,%%f%c\n"  1
reg: CVFF8(reg)   "fstod %%f%0,%%f%c\n"  1
reg: CVFI4(reg)  "fstoi %%f%0,%%f0; st %%f0,[%%sp+64]; ld [%%sp+64],%%%c\n"  (a->syms[0]->u.c.v.i==4?3:LBURG_MAX)

reg: CVFI4(reg)  "fdtoi %%f%0,%%f0; st %%f0,[%%sp+64]; ld [%%sp+64],%%%c\n"  (a->syms[0]->u.c.v.i==8?3:LBURG_MAX)

reg: CVIF4(reg)  "st %%%0,[%%sp+64]; ld [%%sp+64],%%f%c; fitos %%f%c,%%f%c\n"  3

reg: CVIF8(reg)  "st %%%0,[%%sp+64]; ld [%%sp+64],%%f%c; fitod %%f%c,%%f%c\n"  3

rel: EQF8(reg,reg)  "fcmpd %%f%0,%%f%1; nop; fbe"
rel: EQF4(reg,reg)  "fcmps %%f%0,%%f%1; nop; fbe"
rel: GEF8(reg,reg)  "fcmpd %%f%0,%%f%1; nop; fbuge"
rel: GEF4(reg,reg)  "fcmps %%f%0,%%f%1; nop; fbuge"
rel: GTF8(reg,reg)  "fcmpd %%f%0,%%f%1; nop; fbug"
rel: GTF4(reg,reg)  "fcmps %%f%0,%%f%1; nop; fbug"
rel: LEF8(reg,reg)  "fcmpd %%f%0,%%f%1; nop; fbule"
rel: LEF4(reg,reg)  "fcmps %%f%0,%%f%1; nop; fbule"
rel: LTF8(reg,reg)  "fcmpd %%f%0,%%f%1; nop; fbul"
rel: LTF4(reg,reg)  "fcmps %%f%0,%%f%1; nop; fbul"
rel: NEF8(reg,reg)  "fcmpd %%f%0,%%f%1; nop; fbne"
rel: NEF4(reg,reg)  "fcmps %%f%0,%%f%1; nop; fbne"

stmt: rel  "%0 %a; nop\n"  4
reg:  LOADF8(reg)  "# LOADD\n"  2

reg:  NEGF8(reg)  "# NEGD\n"  2

stmt:  ASGNB(reg,INDIRB(reg))  "# ASGNB\n"

%%

#include "esc64.i.c"