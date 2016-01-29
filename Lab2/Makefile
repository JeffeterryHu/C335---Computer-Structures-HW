CC = gcc
CFLAGS = -g
LDFLAGS = 

mywc: mywc.o
	$(CC) $(LDFLAGS) -o mywc mywc.o

mywc.o: mywc.c
	$(CC) $(CFLAGS) -c mywc.c

test: test.o myprintf.o
	$(CC) $(LDFLAGS) -o test test.o myprintf.o

test.o: test.c
	$(CC) $(CFLAGS) -c test.c

myprintf.o: myprintf.c
	$(CC) $(CFLAGS) -c myprintf.c
