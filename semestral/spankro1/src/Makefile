build: ../main

clean:
	rm -f ../main
	@make -C math clean
	@make -C graphics clean
	@make -C ui clean
	@make -C game clean
	@make -C core clean

math/math.o: math/Makefile FORCE
	@make -C math build

graphics/graphics.o: graphics/Makefile FORCE
	@make -C graphics build

ui/ui.o: ui/Makefile FORCE
	@make -C ui build

game/game.o: game/Makefile FORCE
	@make -C game build

core/core.o: core/Makefile FORCE
	@make -C core build

../main: main.cpp math/math.o graphics/graphics.o ui/ui.o game/game.o core/core.o
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^

FORCE: