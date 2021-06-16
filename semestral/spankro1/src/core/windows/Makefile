build: windows.o

clean:
	rm -f $(wildcard *.o)
	@make -C game_stats_window clean
	@make -C main_menu_window clean
	@make -C attacker_picker_window clean
	@make -C game_window clean

game_stats_window/game_stats_window.o: game_stats_window/Makefile FORCE
	@make -C game_stats_window build

main_menu_window/main_menu_window.o: main_menu_window/Makefile FORCE
	@make -C main_menu_window build

attacker_picker_window/attacker_picker_window.o: attacker_picker_window/Makefile FORCE
	@make -C attacker_picker_window build

game_window/game_window.o: game_window/Makefile FORCE
	@make -C game_window build

windows.o: game_stats_window/game_stats_window.o main_menu_window/main_menu_window.o attacker_picker_window/attacker_picker_window.o game_window/game_window.o
	$(LD) -r -o $@ $^

FORCE: