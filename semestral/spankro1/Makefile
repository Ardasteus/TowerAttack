export INCLUDES = -I$(abspath src)

export CXX = g++
export LD = ld

export CXXFLAGS = -g -Og -Wall -Wextra -pedantic -Wno-long-long -fsanitize=address -fsanitize=undefined -fpermissive -lncurses

main:
	@make -C src build

clean:
	@make -C src clean

run:
	@./src/main