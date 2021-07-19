CC = gcc
LIBS = readline
INCLUDE_DIR = .

objects = main.o

all :  $(objects)
	$(CC) -o tsh $(objects) -I$(INCLUDE_DIR) -lreadline


main.o: main.c common.h
	$(CC) -c main.c 

clean: 
	rm *.o tsh