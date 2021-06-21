build: armor_type_factory.o

clean:
	rm -f $(wildcard *.o)

armor_type_factory.o: armor_type_factory.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

FORCE: