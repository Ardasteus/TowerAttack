build: map_handler.o

clean:
	rm -f $(wildcard *.o)

map_handler.o: map_handler.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

FORCE: