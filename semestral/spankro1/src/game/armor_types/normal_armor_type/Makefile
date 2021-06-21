build: normal_armor_type.o

clean:
	rm -f $(wildcard *.o)

normal_armor_type.o: normal_armor_type.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

FORCE: