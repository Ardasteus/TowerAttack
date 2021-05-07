build: label.o

clean:
	rm -f $(wildcard *.o)

label.o: label.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

FORCE: