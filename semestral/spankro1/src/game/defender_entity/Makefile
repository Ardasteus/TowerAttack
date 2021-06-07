build: defender.o

clean:
	rm -f $(wildcard *.o)

defender_template.o: defender_template.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

defender_entity.o: defender_entity.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

defender.o: defender_entity.o defender_template.o
	$(LD) -r -o $@ $^

FORCE: