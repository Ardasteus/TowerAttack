build: graphics.o

clean:
	rm -f $(wildcard *.o)
	@make -C drawer clean
	@make -C window clean
	@make -C color clean

drawer/drawer.o: drawer/Makefile FORCE
	@make -C drawer build

window/window.o: window/Makefile FORCE
	@make -C window build

color/color.o: color/Makefile FORCE
	@make -C color build

graphics.o: drawer/drawer.o window/window.o color/color.o
	$(LD) -r -o $@ $^

FORCE: