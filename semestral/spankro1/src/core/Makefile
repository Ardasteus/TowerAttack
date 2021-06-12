build: core.o

clean:
	rm -f $(wildcard *.o)
	@make -C game_manager clean
	@make -C input_handler clean
	@make -C tile_game_object_pair clean
	@make -C game_stats clean
	@make -C game_stats_window clean
	@make -C level clean
	@make -C save_game clean

game_manager/game_manager.o: game_manager/Makefile FORCE
	@make -C game_manager build

input_handler/input_handler.o: input_handler/Makefile FORCE
	@make -C input_handler build

tile_game_object_pair/tile_game_object_pair.o: tile_game_object_pair/Makefile FORCE
	@make -C tile_game_object_pair build

game_stats/game_stats.o: game_stats/Makefile FORCE
	@make -C game_stats build

game_stats_window/game_stats_window.o: game_stats_window/Makefile FORCE
	@make -C game_stats_window build

level/level.o: level/Makefile FORCE
	@make -C level build

save_game/save_game.o: save_game/Makefile FORCE
	@make -C save_game build

core.o: game_manager/game_manager.o input_handler/input_handler.o tile_game_object_pair/tile_game_object_pair.o game_stats/game_stats.o game_stats_window/game_stats_window.o level/level.o save_game/save_game.o
	$(LD) -r -o $@ $^

FORCE: