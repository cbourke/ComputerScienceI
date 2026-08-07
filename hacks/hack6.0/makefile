#
# makefile for color utilities C library
# assumes cmocka (a unit testing framework) is installed on your
# system
#

CC = gcc
CFLAGS = -Wall -Wextra -std=gnu99
LDLIBS = -lcmocka -lm

.PHONY: clean all

all: utilsTester

utilsTester: colorUtils.o utilsTester.c colorUtils.h
	$(CC) $(CFLAGS) colorUtils.o utilsTester.c -o utilsTester $(LDLIBS)

colorUtils.o: colorUtils.c colorUtils.h
	$(CC) $(CFLAGS) -c colorUtils.c -o colorUtils.o

clean:
	rm -f *~ *.o
