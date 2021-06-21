build: ai_random_strategy.o

clean:
	rm -f $(wildcard *.o)

ai_random_strategy.o: ai_random_strategy.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

FORCE: