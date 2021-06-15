build: closest_attack_mode.o

clean:
	rm -f $(wildcard *.o)

closest_attack_mode.o: closest_attack_mode.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

FORCE: