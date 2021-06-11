build: tile_game_object_pair.o

clean:
	rm -f $(wildcard *.o)

tile_game_object_pair.o: tile_game_object_pair.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

FORCE: