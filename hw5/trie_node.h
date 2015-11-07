// Wenlu Cheng, HW 5, CSE 374
// This is the header file for the trie, which defines the struct node

#ifndef TRIE_NODE_H
#define TRIE_NODE_H

// single node on the trie
struct node{
    struct node* list[8];
    struct word* res_word;
};

// result word linked on the trie node
struct word_list{
    char* str;
    struct word* next;
};

void freeTrie(node* root);

#endif
