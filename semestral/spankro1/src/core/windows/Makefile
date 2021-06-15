build: windows.o

clean:
	rm -f $(wildcard *.o)
	@make -C game_stats_window clean

game_stats_window/game_stats_window.o: game_stats_window/Makefile FORCE
	@make -C game_stats_window build


windows.o: game_stats_window/game_stats_window.o
	$(LD) -r -o $@ $^

FORCE: