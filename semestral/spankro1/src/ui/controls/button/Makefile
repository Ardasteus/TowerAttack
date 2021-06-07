build: button.o

clean:
	rm -f $(wildcard *.o)

button.o: button.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

FORCE: