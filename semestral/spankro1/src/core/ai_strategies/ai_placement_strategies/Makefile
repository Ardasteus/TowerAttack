build: ai_placement_strategies.o

clean:
	rm -f $(wildcard *.o)
	@make -C ai_random_placement_strategy clean

ai_random_placement_strategy/ai_random_placement_strategy.o: ai_random_placement_strategy/Makefile FORCE
	@make -C ai_random_placement_strategy build

ai_placement_strategies.o: ai_random_placement_strategy/ai_random_placement_strategy.o
	$(LD) -r -o $@ $^

FORCE: