CFLAGS=-Wall -O2 -I..
LDFLAGS=-Wall -O2 -I..

all: adjacencylist

%o: %.c %.h
	$(CC) -c -o $@ $<

adjacencylist: adjacencylist.c graph.o ../list/list.o
	$(CC) -o $@ $^ $(LDFLAGS)
	
clean:
	rm -f *.o adjacencylist
