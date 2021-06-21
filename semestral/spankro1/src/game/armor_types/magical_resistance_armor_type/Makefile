build: magical_resistance_armor_type.o

clean:
	rm -f $(wildcard *.o)

magical_resistance_armor_type.o: magical_resistance_armor_type.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

FORCE: