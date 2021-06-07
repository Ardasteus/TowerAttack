build: game.o

clean:
	rm -f $(wildcard *.o)
	@make -C game_object clean
	@make -C attacker_entity clean
	@make -C defender_entity clean
	@make -C window clean

game_object/game_object.o: game_object/Makefile FORCE
	@make -C game_object build

attacker_entity/attacker.o: attacker_entity/Makefile FORCE
	@make -C attacker_entity build

defender_entity/defender.o: defender_entity/Makefile FORCE
	@make -C defender_entity build

window/window.o: window/Makefile FORCE
	@make -C window build

game.o: game_object/game_object.o defender_entity/defender.o attacker_entity/attacker.o window/window.o
	$(LD) -r -o $@ $^

FORCE: