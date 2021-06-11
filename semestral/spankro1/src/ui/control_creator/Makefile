build: control_creator.o

clean:
	rm -f $(wildcard *.o)

control_creator.o: control_creator.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

FORCE: