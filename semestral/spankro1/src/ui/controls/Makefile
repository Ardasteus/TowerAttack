build: controls.o

clean:
	rm -f $(wildcard *.o)
	@make -C gui_object clean
	@make -C label clean

gui_object/gui_object.o: gui_object/Makefile FORCE
	@make -C gui_object build

label/label.o: label/Makefile FORCE
	@make -C label build

controls.o: gui_object/gui_object.o label/label.o
	$(LD) -r -o $@ $^	

FORCE: