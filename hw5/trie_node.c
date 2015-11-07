// Wenlu Cheng, CSE 374, HW 5
// This is the file building up the trie data structure

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "tire_node.h"

struct node* add_node(){
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    for(int i = 0; i < 8; i++){
        tmp-> list[i] = NULL;
        tmp-> res_word = NULL;
    }
    return tmp;
}

struct node* add_node()


// copy the given string into the wordlist
struct word_list* newStr(char* text){
    char* copy_s = (char *)malloc(sizeof(char) * strlen(text));
    strncpy(copy_s, text, strlen(text));
    struct word* tmp = (struct word*)malloc(sizeof(struct word));
    tmp-> str = copy_s;
    tmp -> next = NULL;
    return tmp;
}


