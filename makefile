CC = gcc
CFLAGS = -g -O2
OBJECTS = auto-cipher.o

main.exe : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o main.exe

auto-cipher.o : auto-cipher.c
	$(CC) $(CFLAGS) -c auto-cipher.c