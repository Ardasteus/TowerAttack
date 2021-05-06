build: vector.o

clean:
	rm -f $(wildcard *.o)

vector.o: ivector2.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

FORCE: