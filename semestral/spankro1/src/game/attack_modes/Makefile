build: attack_modes.o

clean:
	rm -f $(wildcard *.o)
	@make -C aoe_attack_mode clean
	@make -C closest_attack_mode clean
	@make -C furthest_attack_mode clean
	@make -C attack_mode_factory clean

aoe_attack_mode/aoe_attack_mode.o: aoe_attack_mode/Makefile FORCE
	@make -C aoe_attack_mode build

closest_attack_mode/closest_attack_mode.o: closest_attack_mode/Makefile FORCE
	@make -C closest_attack_mode build

furthest_attack_mode/furthest_attack_mode.o: furthest_attack_mode/Makefile FORCE
	@make -C furthest_attack_mode build

attack_mode_factory/attack_mode_factory.o: attack_mode_factory/Makefile FORCE
	@make -C attack_mode_factory build

attack_modes.o: closest_attack_mode/closest_attack_mode.o aoe_attack_mode/aoe_attack_mode.o furthest_attack_mode/furthest_attack_mode.o attack_mode_factory/attack_mode_factory.o
	$(LD) -r -o $@ $^

FORCE: