build: game.o

clean:
	rm -f $(wildcard *.o)
	@make -C game_object clean
	@make -C attacker_entity clean
	@make -C defender_entity clean
	@make -C attack_modes clean

game_object/game_object.o: game_object/Makefile FORCE
	@make -C game_object build

attacker_entity/attacker.o: attacker_entity/Makefile FORCE
	@make -C attacker_entity build

defender_entity/defender.o: defender_entity/Makefile FORCE
	@make -C defender_entity build

attack_modes/attack_modes.o: attack_modes/Makefile FORCE
	@make -C attack_modes build

game.o: game_object/game_object.o defender_entity/defender.o attacker_entity/attacker.o attack_modes/attack_modes.o
	$(LD) -r -o $@ $^

FORCE: