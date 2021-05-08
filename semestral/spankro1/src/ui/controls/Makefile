build: controls.o

clean:
	rm -f $(wildcard *.o)
	@make -C gui_object clean
	@make -C label clean
	@make -C focusable_gui_object clean
	@make -C textbox clean

gui_object/gui_object.o: gui_object/Makefile FORCE
	@make -C gui_object build

label/label.o: label/Makefile FORCE
	@make -C label build

focusable_gui_object/focusable_gui_object.o: focusable_gui_object/Makefile FORCE
	@make -C focusable_gui_object build

textbox/textbox.o: textbox/Makefile FORCE
	@make -C textbox build

controls.o: gui_object/gui_object.o label/label.o focusable_gui_object/focusable_gui_object.o textbox/textbox.o
	$(LD) -r -o $@ $^	

FORCE: