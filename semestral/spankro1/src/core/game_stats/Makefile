build: game_stats.o

clean:
	rm -f $(wildcard *.o)

game_stats.o: game_stats.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

FORCE: