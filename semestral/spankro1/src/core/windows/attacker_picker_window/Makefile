build: attacker_picker_window.o

clean:
	rm -f $(wildcard *.o)

attacker_picker_window.o: attacker_picker_window.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

FORCE: