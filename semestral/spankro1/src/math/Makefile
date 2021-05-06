build: math.o

clean:
	rm -f $(wildcard *.o)
	@make -C vector clean

vector/vector.o: vector/Makefile FORCE
	@make -C vector build

math.o: vector/vector.o
	$(LD) -r -o $@ $^

FORCE: