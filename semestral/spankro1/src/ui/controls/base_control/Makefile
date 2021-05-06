build: base_control.o

clean:
	rm -f $(wildcard *.o)

base_control.o: base_control.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

FORCE: