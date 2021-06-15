build: game_stats_window.o

clean:
	rm -f $(wildcard *.o)

game_stats_window.o: game_stats_window.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

FORCE: