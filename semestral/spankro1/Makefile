export INCLUDES = -I$(abspath src)

export CXX = g++
export LD = ld

export CXXFLAGS = -g -Og -Wall -Wextra -pedantic -Wno-long-long -fsanitize=address -fsanitize=undefined -fpermissive -lncurses

main: FORCE
	@make -C src build

compile: FORCE
	@make -C src build 

all: FORCE
	@make -C src build 

clean: FORCE
	rm -rf doc
	@make -C src clean

run: FORCE
	@./main

doc: FORCE
	@doxygen Doxyfile

FORCE:
