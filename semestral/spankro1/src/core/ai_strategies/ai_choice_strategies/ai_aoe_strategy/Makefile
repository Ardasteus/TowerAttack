build: ai_aoe_strategy.o

clean:
	rm -f $(wildcard *.o)

ai_aoe_strategy.o: ai_aoe_strategy.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

FORCE: