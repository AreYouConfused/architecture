all: div.obj mult.obj rshift.obj masm_mrd

run_div: prom.dat div.obj
	./mic1 prom.dat div.obj 0 2048
run_mult: prom.dat mult.obj
	./mic1 prom.dat mult.obj 0 2048
run_rshift: prom.dat rshift.obj
	./mic1 prom.dat rshift.obj 0 2048
div.obj: a4_div_test.asm masm_mrd
	./masm_mrd < a4_div_test.asm > div.obj
mult.obj: a4_mult_test.asm masm_mrd
	./masm_mrd < a4_mult_test.asm > mult.obj
rshift.obj: a4_rshift_test.asm masm_mrd
	./masm_mrd < a4_rshift_test.asm > rshift.obj
prom.dat: microcode_rmd.mc
	./mcc < microcode_rmd.mc > prom.dat
masm_mrd: mic1symasm_mrd.o lex.yy.o
	gcc -o masm_mrd mic1symasm_mrd.o lex.yy.o
mic1symasm_mrd.o:  mic1symasm_mrd.c
	gcc -c -g mic1symasm_mrd.c
lex.yy.o:  lex.yy.c
	gcc -c -g lex.yy.c
lex.yy.c: mic1symasm_mrd.ll
	flex mic1symasm_mrd.ll
clean:
	rm lex.yy.o lex.yy.c mic1symasm_mrd.o masm_mrd div.obj mult.obj rshift.obj || true
