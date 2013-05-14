CFLAGS=-Wall -O2 -I..
LDFLAGS=-Wall -O2 -I..

all: list

%o: %.c %.h
	$(CC) -c -o $@ $<

list: main.c list.o
	$(CC) -o $@ $^ $(LDFLAGS)
	
clean:
	rm -f *.o list
