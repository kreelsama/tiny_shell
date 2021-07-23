CC = gcc
LIBS = readline
INCLUDE_DIR = .
CSTD = c11

objects = main.o input.o

all :  $(objects)
	$(CC) -o tsh -std=$(CSTD) $(objects) -I$(INCLUDE_DIR) -lreadline 


main.o: main.c common.h
	$(CC) -c main.c -std=$(CSTD)

input.o: input.c common.h
	$(CC) -c input.c -std=$(CSTD)

clean: 
	rm *.o tsh