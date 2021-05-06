build: window.o

clean:
	rm -f $(wildcard *.o)

window.o: window.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

FORCE: