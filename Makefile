CC = gcc
CFLAGS = -Wall -g
all: StrList
# Creating Executables
StrList: main.o StrList.o
	$(CC) $(CFLAGS) -o StrList main.o StrList.o
# Build object files
main.o: main.c StrList.h
	$(CC) $(CFLAGS) -c main.c
StrList.o: StrList.c StrList.h
	$(CC) $(CFLAGS) -c StrList.c
# Clean build files
clean:
	rm -f *.o *.a StrList 