// Wenlu Cheng, CSE 374
// This file takes the user input and return the string that matches up the digit pattern

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"trie_node.h"
#define MaxLine 200


int main(int argc, char* argv[]){
    struct node* root;
    // struct wordList* res;
    FILE* fr;
    char line[MaxLine];
    struct node* runner;
    if(argc < 2){
        perror("T9 takes 2 arguments");
        return -1;
    }
    fr = fopen(argv[1], "rt");
    if(!fr){
        perror("File does not exist");
        return -1;
    }
    //construct the overall root
    root = create_root();
    while(fgets(line, MaxLine, fr)){
        int end = strlen(line) - 1;
        // remove the new line at the end
        if(line[end] == '\n'){
            line[end] = '\0';
        }else{
            line[end + 1] = '\0';
        }
        runner = root;
        create_trie(line, runner);
    }
}

