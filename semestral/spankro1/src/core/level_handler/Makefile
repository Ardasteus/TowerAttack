build: level_handler.o

clean:
	rm -f $(wildcard *.o)

level_handler.o: level_handler.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

FORCE: