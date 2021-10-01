rfib.obj:rfib.asm
	./masm < rfib.asm > rfib.obj

run:rfib.obj
	./mic1 prom.dat rfib.obj 0 2048

clean:
	rm rfib.obj