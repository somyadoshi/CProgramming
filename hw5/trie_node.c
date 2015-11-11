// Wenlu Cheng, CSE 374, HW 5
// This is the file building up the trie data structure

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "trie_node.h"

// construct the head root
struct node* create_root(){
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    for(int i = 0; i < 8; i++){
        tmp->list[i] = NULL;
        tmp->res_word = NULL;
    }
    return tmp;
}

// free the trie recursively
void freeTrie(struct node* root){
    if(root){
        for(int i = 0; i < 8; i++){
            if(root-> list[i]){
                freeTrie(root-> list[i]);
            }
            if(root->res_word){
                freeWordList(root->res_word);
            }
        }
    }
}

// free the list of words that share the same digit pattern
void freeWordList(struct wordList* res_word){
    if(res_word->next) {
        freeWordList(res_word->next);
    }
    free(res_word->str);
    free(res_word);
}

int convertStr(char key){
    switch(key){
        case('a'):
        case('b'):
        case('c'):
            return 2;  
        case('d'):
        case('e'):
        case('f'):
            return 3;
        case('g'):
        case('h'):
        case('i'):
            return 4;
        case('j'):
        case('k'):
        case('l'):
            return 5;
        case('m'):
        case('n'):
        case('o'):
            return 6;
        case('p'):
        case('q'):
        case('r'):
        case('s'):
            return 7;        
        case('t'):
        case('u'):
        case('v'):
        case('w'):
            return 8;
        case('x'):
        case('y'):
        case('z'):
            return 9;
        default: 
            return -1;
    }
}

// build up the tree based on the key given
void create_trie(char* word, struct node* root){
    for(int i = 0; i < strlen(word) - 1; i++){
        int key = convertStr(word[i]);
        // if at index position there is no node
        if(!root->list[key - 2]){
            root->list[key - 2] = create_root();
        }
        // go to next level
        root = root->list[key - 2];
    }
    // deal with the bottom node
    int low = convertStr(word[strlen(word) - 1]);
    // there is a word node existed
	if(root->list[low - 2]){
        root = root->list[low - 2];
        struct wordList* tmp = root->res_word;
        // if there is next in the wordlist
		while(tmp->next){
			tmp = tmp->next;
		}
        struct wordList* newptr = newStr(word);
        tmp->next = newptr;
    }else{
        root->list[low - 2] = create_root();
        root = root->list[low - 2];
        root->res_word = newStr(word);
    }
}

char* search(struct node* root){
    return root->list[5]->list[4]->list[0]->list[3]->list[5]->res_word->str;
}


// copy the given string into the wordlist
struct wordList* newStr(char* text){
    char* copy_s = (char *)malloc(sizeof(char) * strlen(text));
    strncpy(copy_s, text, strlen(text));
    struct wordList* tmp = (struct wordList*)malloc(sizeof(struct wordList));
    tmp->str = copy_s;
    tmp->next = NULL;
    return tmp;
}


