build: game_manager.o

clean:
	rm -f $(wildcard *.o)

game_manager.o: game_manager.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

FORCE: