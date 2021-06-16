build: attacker_definition_handler.o

clean:
	rm -f $(wildcard *.o)

attacker_definition_handler.o: attacker_definition_handler.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

FORCE: