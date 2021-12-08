all: a7

run: a7
	./a7

%: %.c
	clang -g -O3 -o $@ $^ || gcc -g -O3 -o $@ $^

clean:
	rm -f a7
