build: ui.o

clean:
	rm -f $(wildcard *.o)
	@make -C controls clean
	@make -C window clean
	@make -C control_creator clean

controls/controls.o: controls/Makefile FORCE
	@make -C controls build

window/window.o: window/Makefile FORCE
	@make -C window build

control_creator/control_creator.o: control_creator/Makefile FORCE
	@make -C control_creator build

ui.o: window/window.o controls/controls.o control_creator/control_creator.o
	$(LD) -r -o $@ $^

FORCE: