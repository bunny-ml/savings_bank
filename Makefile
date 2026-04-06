
PROGRAM = bank
CC = gcc
CFLAGS = `pkg-config --cflags gtk4`
LIBS = `pkg-config --libs gtk4`

$(PROGRAM): $(PROGRAM).c
	$(CC) $(PROGRAM).c -o $(PROGRAM) $(CFLAGS) $(LIBS)

clear: 
	rm $(PROGRAM)
