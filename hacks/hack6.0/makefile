# Makefile for color utilities C library
# Assumes CMocka (a unit testing framework) is installed on your system

CC = gcc
CFLAGS = -Wall -std=gnu99
LDFLAGS = -lcmocka -lm

TARGET = utilsTester
SRCS = colorUtils.c utilsTester.c

OBJS = $(SRCS:.c=.o)

//PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LDFLAGS)

colorUtils.o: colorUtils.c colorUtils.h

clean:
	rm -f $(OBJS) $(TARGET) *~




