all: addints

run: addints
	./mic1 prom_mrd.dat addints 0 2048

addints: linker main.obj writestring.obj readint.obj addints.obj writeint.obj xbsywt.obj rbsywt.obj
	./linker main.obj writestring.obj readint.obj addints.obj writeint.obj xbsywt.obj rbsywt.obj > addints

linker: linker.o
	gcc -o linker linker.o

linker.o: linker.c
	gcc -c -g linker.c

%.obj: %.asm
	./masm_mrd -o < $< > $@

clean:
	rm -f addints linker *.o *.obj
