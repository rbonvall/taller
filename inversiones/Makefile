CCFLAGS = -Wall
INPUT = input
OUTPUT = output

all: inv1 inv2 inv3

inv1: inv1.c
	gcc $(CCFLAGS) $^ -o $@
inv2: inv2.c
	gcc $(CCFLAGS) $^ -o $@
inv3: inv3.cpp
	g++ $(CCFLAGS) $^ -o $@

clean:
	rm inv{1,2,3}

.PHONY: all clean 

