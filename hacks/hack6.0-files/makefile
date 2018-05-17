#
# makefile for color utilities C library
# assumes cmocka (a unit testing framework) is installed on your
# system 
#

CC = gcc
FLAGS = -Wall
INCLUDES = -l cmocka -lm

utilsTester: colorUtils.o utilsTester.c
	$(CC) $(FLAGS) $(INCLUDES) colorUtils.o utilsTester.c -o utilsTester

colorUtils.o: colorUtils.c colorUtils.h
	$(CC) $(FLAGS) $(INCLUDES) -c colorUtils.c -o colorUtils.o

clean:
	rm -f *~ *.o
