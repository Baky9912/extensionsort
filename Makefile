
CFLAGS = -Wall -O3
CC = gcc

extensionsorter: sorter.o extensionsorter.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o extensionsorter
