build: controls.o

clean:
	rm -f $(wildcard *.o)
	@make -C base_control clean

base_control/base_control.o: base_control/Makefile FORCE
	@make -C base_control build

controls.o: base_control/base_control.o
	$(LD) -r -o $@ $^	

FORCE: