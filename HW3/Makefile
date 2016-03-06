# Makefile
# Shichao Hu (hushi)
# Part of: HW3
# Created on: 3/1/2016
# Last modified: 3/6/2016

CC = gcc
CFLAGS = -g
LDFLAGS =


hw3: hw3.o
	$(CC) $(LDFLAGS) -o hw3 hw3.o
hw3.o: hw3.c
	$(CC) $(CFLAGS) -c hw3.c
clean:
	rm hw3.o hw3
