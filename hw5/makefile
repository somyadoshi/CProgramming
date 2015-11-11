# Wenlu Cheng, CSE 374
# HW 5
# compiles files for T9


T9: T9.o trie_node.o
	gcc -Wall -std=c11 -g -o T9 T9.o trie_node.o

T9.o: trie_node.h T9.c
	gcc -Wall -std=c11 -g -c T9.c

trie_node.o: trie_node.c trie_node.h
	gcc -Wall -std=c11 -g -c trie_node.c

clean:
	rm -f *.o T9 *~
