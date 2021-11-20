all: 

run: prom_mrd.dat scan_mult_print.obj
	./mic1 prom_mrd.dat scan_mult_print.obj 0 2048

scan_mult_print.obj: scan_mult_print.asm masm_mrd
	./masm_mrd < scan_mult_print.asm > $@
clean:
	rm scan_mult_print.obj
