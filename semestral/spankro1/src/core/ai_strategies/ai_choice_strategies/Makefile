build: ai_choice_strategies.o

clean:
	rm -f $(wildcard *.o)
	@make -C ai_aoe_strategy clean
	@make -C ai_closest_strategy clean
	@make -C ai_furthest_strategy clean
	@make -C ai_cyclic_strategy clean

ai_aoe_strategy/ai_aoe_strategy.o: ai_aoe_strategy/Makefile FORCE
	@make -C ai_aoe_strategy build

ai_closest_strategy/ai_closest_strategy.o: ai_closest_strategy/Makefile FORCE
	@make -C ai_closest_strategy build

ai_furthest_strategy/ai_furthest_strategy.o: ai_furthest_strategy/Makefile FORCE
	@make -C ai_furthest_strategy build

ai_cyclic_strategy/ai_cyclic_strategy.o: ai_cyclic_strategy/Makefile FORCE
	@make -C ai_cyclic_strategy build

ai_choice_strategies.o: ai_aoe_strategy/ai_aoe_strategy.o ai_closest_strategy/ai_closest_strategy.o ai_furthest_strategy/ai_furthest_strategy.o ai_cyclic_strategy/ai_cyclic_strategy.o
	$(LD) -r -o $@ $^

FORCE: