build: textbox.o

clean:
	rm -f $(wildcard *.o)

textbox.o: textbox.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

FORCE: