build: main

clean:
	rm -f main
	@make -C math clean
	@make -C graphics clean
	@make -C ui clean

math/math.o: math/Makefile FORCE
	@make -C math build

graphics/graphics.o: graphics/Makefile FORCE
	@make -C graphics build

ui/ui.o: ui/Makefile FORCE
	@make -C ui build

main: main.cpp math/math.o graphics/graphics.o ui/ui.o
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^

FORCE: