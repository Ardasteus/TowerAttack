build: defender_definition_handler.o

clean:
	rm -f $(wildcard *.o)

defender_definition_handler.o: defender_definition_handler.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

FORCE: