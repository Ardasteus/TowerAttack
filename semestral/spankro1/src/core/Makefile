build: core.o

clean:
	rm -f $(wildcard *.o)
	@make -C game_manager clean
	@make -C input_handler clean
	@make -C tile_game_object_pair clean
	@make -C game_stats clean
	@make -C windows clean
	@make -C level clean
	@make -C save_game clean
	@make -C ai_agent clean
	@make -C attacker_definition_handler clean
	@make -C defender_definition_handler clean
	@make -C level_handler clean
	@make -C map_handler clean

game_manager/game_manager.o: game_manager/Makefile FORCE
	@make -C game_manager build

input_handler/input_handler.o: input_handler/Makefile FORCE
	@make -C input_handler build

tile_game_object_pair/tile_game_object_pair.o: tile_game_object_pair/Makefile FORCE
	@make -C tile_game_object_pair build

game_stats/game_stats.o: game_stats/Makefile FORCE
	@make -C game_stats build

windows/windows.o: windows/Makefile FORCE
	@make -C windows build

level/level.o: level/Makefile FORCE
	@make -C level build

save_game/save_game.o: save_game/Makefile FORCE
	@make -C save_game build

ai_agent/ai_agent.o: ai_agent/Makefile FORCE
	@make -C ai_agent build

attacker_definition_handler/attacker_definition_handler.o: attacker_definition_handler/Makefile FORCE
	@make -C attacker_definition_handler build

defender_definition_handler/defender_definition_handler.o:defender_definition_handler/Makefile FORCE
	@make -C defender_definition_handler build

level_handler/level_handler.o: level_handler/Makefile FORCE
	@make -C level_handler build

map_handler/map_handler.o: map_handler/Makefile FORCE
	@make -C map_handler build

core.o: game_manager/game_manager.o input_handler/input_handler.o tile_game_object_pair/tile_game_object_pair.o game_stats/game_stats.o windows/windows.o level/level.o save_game/save_game.o ai_agent/ai_agent.o attacker_definition_handler/attacker_definition_handler.o defender_definition_handler/defender_definition_handler.o level_handler/level_handler.o map_handler/map_handler.o
	$(LD) -r -o $@ $^

FORCE: