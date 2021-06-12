build: save_game.o

clean:
	rm -f $(wildcard *.o)

save_game.o: save_game.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

FORCE: