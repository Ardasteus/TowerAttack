build: game_object.o

clean:
	rm -f $(wildcard *.o)

game_object.o: game_object.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

FORCE: