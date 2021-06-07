build: core.o

clean:
	rm -f $(wildcard *.o)
	@make -C game_manager clean
	@make -C input_handler clean

game_manager/game_manager.o: game_manager/Makefile FORCE
	@make -C game_manager build

input_handler/input_handler.o: input_handler/Makefile FORCE
	@make -C input_handler build

core.o: game_manager/game_manager.o input_handler/input_handler.o
	$(LD) -r -o $@ $^

FORCE: