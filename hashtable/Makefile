CFLAGS=-Wall -O2 -I..
LDFLAGS=-Wall -O2 -I..

all: hashtable

%o: %.c %.h
	$(CC) -c -o $@ $<

hashtable: main.c hashtable.o ../list/list.o
	$(CC) -o $@ $^ $(LDFLAGS)
	
clean:
	rm -f *.o hashtable
