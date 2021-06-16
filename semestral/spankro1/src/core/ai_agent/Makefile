build: ai_agent.o

clean:
	rm -f $(wildcard *.o)

ai_agent.o: ai_agent.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

FORCE: