build: main_menu_window.o

clean:
	rm -f $(wildcard *.o)

main_menu_window.o: main_menu_window.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

FORCE: