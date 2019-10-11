#
# makefile for color utilities C library
# assumes cmocka (a unit testing framework) is installed on your
# system 
#

CC = gcc
FLAGS = -Wall -std=gnu99
INCLUDES = -l cmocka -lm

utilsTester: colorUtils.o utilsTester.c
	$(CC) $(FLAGS) colorUtils.o utilsTester.c -o utilsTester $(INCLUDES)

colorUtils.o: colorUtils.c colorUtils.h
	$(CC) $(FLAGS) -c colorUtils.c -o colorUtils.o $(INCLUDES)

clean:
	rm -f *~ *.o
