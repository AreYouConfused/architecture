CC = gcc
CFLAGS = -std=c18 -g -Og -Wall -O3 -c -o
LFLAGS = -o
OBJ = main.o
DEPS = 
LIBS = 
BIN = floatadder

all: $(BIN) $(DEPS)

$(BIN): $(OBJ)
	$(CC) $(LFLAGS) $@ $(OBJ) $(LIBS)

%.o: %.c %.h
	$(CC) $(CFLAGS) $@ $<

%.o: %.c
	$(CC) $(CFLAGS) $@ $<

clean:
	@rm $(OBJ) $(BIN) 2>/dev/null || true

