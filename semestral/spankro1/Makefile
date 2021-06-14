export INCLUDES = -I$(abspath src)

export CXX = g++
export LD = ld

export CXXFLAGS = -g -Os -Wall -Wextra -pedantic -Wno-long-long -fpermissive -lncurses

spankro1: FORCE
	@make -C src build

compile: FORCE
	@make -C src build 

all: FORCE
	@make -C src build 

clean: FORCE
	rm -f spankro1
	rm -rf doc
	@make -C src clean

run: FORCE
	@./spankro1

doc: FORCE
	@doxygen Doxyfile

FORCE:
