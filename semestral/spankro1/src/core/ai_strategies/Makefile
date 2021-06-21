build: ai_strategies.o

clean:
	rm -f $(wildcard *.o)
	@make -C ai_placement_strategies clean
	@make -C ai_choice_strategies clean

ai_choice_strategies/ai_choice_strategies.o: ai_choice_strategies/Makefile FORCE
	@make -C ai_choice_strategies build

ai_placement_strategies/ai_placement_strategies.o: ai_placement_strategies/Makefile FORCE
	@make -C ai_placement_strategies build

ai_strategies.o: ai_choice_strategies/ai_choice_strategies.o ai_placement_strategies/ai_placement_strategies.o 
	$(LD) -r -o $@ $^

FORCE: