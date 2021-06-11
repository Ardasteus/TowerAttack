build: level.o

clean:
	rm -f $(wildcard *.o)

level.o: level.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

FORCE: