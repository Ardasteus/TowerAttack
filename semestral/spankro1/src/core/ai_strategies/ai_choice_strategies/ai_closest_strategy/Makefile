build: ai_closest_strategy.o

clean:
	rm -f $(wildcard *.o)

ai_closest_strategy.o: ai_closest_strategy.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

FORCE: