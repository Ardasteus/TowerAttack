build: gui_object.o

clean:
	rm -f $(wildcard *.o)

gui_object.o: gui_object.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

FORCE: