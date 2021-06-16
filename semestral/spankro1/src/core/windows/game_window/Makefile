build: game_window.o

clean:
	rm -f $(wildcard *.o)

game_window.o: game_window.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

FORCE: