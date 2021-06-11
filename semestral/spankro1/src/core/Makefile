build: core.o

clean:
	rm -f $(wildcard *.o)
	@make -C game_manager clean
	@make -C input_handler clean
	@make -C tile_game_object_pair clean

game_manager/game_manager.o: game_manager/Makefile FORCE
	@make -C game_manager build

input_handler/input_handler.o: input_handler/Makefile FORCE
	@make -C input_handler build

tile_game_object_pair/tile_game_object_pair.o: tile_game_object_pair/Makefile FORCE
	@make -C tile_game_object_pair build

core.o: game_manager/game_manager.o input_handler/input_handler.o tile_game_object_pair/tile_game_object_pair.o
	$(LD) -r -o $@ $^

FORCE: