CC = gcc
CFLAGS = -Wall

all: bfs dfs topo

bfs: bfs.c
	$(CC) $(CFLAGS) $< -o $@
dfs: dfs.c
	$(CC) $(CFLAGS) $< -o $@
topo: topo.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm bfs dfs topo

.PHONY: clean all
