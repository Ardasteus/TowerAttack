build: aoe_attack_mode.o

clean:
	rm -f $(wildcard *.o)

aoe_attack_mode.o: aoe_attack_mode.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

FORCE: