build: color.o

clean:
	rm -f $(wildcard *.o)

color.o: color_pair.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

FORCE: