build: window.o

clean:
	rm -f $(wildcard *.o)

window.o: gui_window.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

FORCE: