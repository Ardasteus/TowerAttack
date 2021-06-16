build: attack_mode_factory.o

clean:
	rm -f $(wildcard *.o)

attack_mode_factory.o: attack_mode_factory.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

FORCE: