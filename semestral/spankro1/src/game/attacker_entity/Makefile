build: attacker.o

clean:
	rm -f $(wildcard *.o)

attacker_template.o: attacker_template.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

attacker_entity.o: attacker_entity.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

attacker.o: attacker_entity.o attacker_template.o
	$(LD) -r -o $@ $^

FORCE: