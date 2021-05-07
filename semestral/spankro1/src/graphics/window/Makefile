build: window.o

clean:
	rm -f $(wildcard *.o)

window_wrapper.o: window_wrapper.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

window_border.o: window_border.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

base_window.o: base_window.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

window.o: base_window.o window_wrapper.o window_border.o
	$(LD) -r -o $@ $^

FORCE:
