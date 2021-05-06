build: ui.o

clean:
	rm -f $(wildcard *.o)
	@make -C controls clean
	@make -C window clean

controls/controls.o: controls/Makefile FORCE
	@make -C controls build

window/window.o: window/Makefile FORCE
	@make -C window build

ui.o: window/window.o controls/controls.o
	$(LD) -r -o $@ $^

FORCE: