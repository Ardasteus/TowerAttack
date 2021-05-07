build: color.o

clean:
	rm -f $(wildcard *.o)

color_pair.o: color_pair.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

color_pair_comparator.o: color_pair_comparator.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

color.o: color_pair.o color_pair_comparator.o
	$(LD) -r -o $@ $^

FORCE: