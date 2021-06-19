build: ai_cyclic_strategy.o

clean:
	rm -f $(wildcard *.o)

ai_cyclic_strategy.o: ai_cyclic_strategy.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

FORCE: