CC = gcc
CFLAGS = -std=c18 -g -Og -Wall -Werror -O3 -c -o
LFLAGS = -o
OBJ = f2bits.o
DEPS = 
LIBS = 
BIN = f2bits

all: $(BIN) $(DEPS)

$(BIN): $(OBJ)
	$(CC) $(LFLAGS) $@ $(OBJ) $(LIBS)

%.o: %.c %.h
	$(CC) $(CFLAGS) $@ $<

%.o: %.c
	$(CC) $(CFLAGS) $@ $<

clean:
	@rm $(OBJ) $(BIN) 2>/dev/null || true

