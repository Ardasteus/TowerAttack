build: drawer.o

clean:
	rm -f $(wildcard *.o)

drawer.o: drawer.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

FORCE: