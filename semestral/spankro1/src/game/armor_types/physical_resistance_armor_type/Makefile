build: physical_resistance_armor_type.o

clean:
	rm -f $(wildcard *.o)

physical_resistance_armor_type.o: physical_resistance_armor_type.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

FORCE: