CCFLAGS = -O2 -Wall

PROGRAMS = ord1 ord2 ord3 ord4

all: $(PROGRAMS)

clean:
	rm $(PROGRAMS)

#  $^ : el primer prerrequisito
#  $@ : el objetivo
#  %  : comodin

ord1: ord1.c
	gcc $(CCFLAGS) $^ -o $@
ord2: ord2.c
	gcc $(CCFLAGS) $^ -o $@
ord3: ord3.cpp
	g++ $(CCFLAGS) $^ -o $@
ord4: ord4.cpp
	g++ $(CCFLAGS) $^ -o $@

