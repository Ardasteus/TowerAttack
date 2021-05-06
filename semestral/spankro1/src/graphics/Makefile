build: graphics.o

clean:
	rm -f $(wildcard *.o)
	@make -C drawer clean
	@make -C window clean

drawer/drawer.o: drawer/Makefile FORCE
	@make -C drawer build

window/window.o: window/Makefile FORCE
	@make -C window build

graphics.o: drawer/drawer.o window/window.o
	$(LD) -r -o $@ $^

FORCE: