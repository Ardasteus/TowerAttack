build: input_handler.o

clean:
	rm -f $(wildcard *.o)

input_handler.o: input_handler.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

FORCE: