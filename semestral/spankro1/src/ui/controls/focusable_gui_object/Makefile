build: focusable_gui_object.o

clean:
	rm -f $(wildcard *.o)

focusable_gui_object.o: focusable_gui_object.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

FORCE: