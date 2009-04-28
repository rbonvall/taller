CC = gcc
CCFLAGS = -Wall -O2

all: 1-subsets 2-permutations 3-nqueens

1-subsets: 1-subsets.c
	$(CC) $(CCFLAGS) $< -o $@
2-permutations: 2-permutations.c
	$(CC) $(CCFLAGS) $< -o $@
3-nqueens: 3-nqueens.c
	$(CC) $(CCFLAGS) $< -o $@

clean:
	rm 1-subsets 2-permutations 3-nqueens
