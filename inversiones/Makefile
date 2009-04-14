CCFLAGS = -Wall
INPUT = input
OUTPUT = output

all: inv1 inv2 inv3 inv4

inv1: inv1.c
	gcc $(CCFLAGS) $< -o $@
inv2: inv2.c
	gcc $(CCFLAGS) $< -o $@
inv3: inv3.cpp
	g++ $(CCFLAGS) $< -o $@
inv4: inv4.cpp
	g++ $(CCFLAGS) $< -o $@

test: inv2 inv3 inv4
	@for program in $^; do \
	    if ./$$program < $(INPUT) | diff -q - $(OUTPUT); then \
	        echo "$$program pasa el caso de prueba :)"; \
	    else \
	        echo "$$program no pasa el caso de prueba :("; \
	    fi; \
	done

clean:
	rm inv{1,2,3,4}

.PHONY: all clean test

