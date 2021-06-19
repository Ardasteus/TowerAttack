build: ai_strategies.o

clean:
	rm -f $(wildcard *.o)
	@make -C ai_choice_strategies clean

ai_choice_strategies/ai_choice_strategies.o: ai_choice_strategies/Makefile FORCE
	@make -C ai_choice_strategies build

ai_strategies.o: ai_choice_strategies/ai_choice_strategies.o 
	$(LD) -r -o $@ $^

FORCE: