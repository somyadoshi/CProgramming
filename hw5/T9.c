// Wenlu Cheng, CSE 374
// This file takes the user input and return the string
// that matches up the digit pattern

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"trie_node.h"
#define MaxLine 200
#define Input_Len 100

void searchWord(struct node* root);

int main(int argc, char* argv[]) {
    struct node* root;
    FILE* fr;
    char line[MaxLine];
    struct node* runner;
    if (argc < 2) {
        perror("T9 takes 2 arguments");
        return -1;
    }
    fr = fopen(argv[1], "rt");
    if (!fr) {
        perror("File does not exist");
        return -1;
    }
    // construct the overall root
    root = create_root();
    while (fgets(line, MaxLine, fr)) {
        int end = strlen(line) - 1;
        // remove the new line at the end
        if (line[end] == '\n') {
            line[end] = '\0';
        }
        runner = root;
        create_trie(line, runner);
    }
    fclose(fr);
    searchWord(root);
    freeTrie(root);  // free after using the trie
    return 0;
}

// this function returns the searched digit word in the trie
void searchWord(struct node* root) {
    struct node* runner = root;
    struct wordList* cur;
    char input[Input_Len];
    int flag = 0;  // flag used to print there are no more T9onyms
    int invalid = 0;  // flag for invalid input
    int p_counter = 0;  // count how many # sign input
    printf("Enter \"exit\" to quit.\n");
    while (1) {
        printf("Enter Key Sequence (or \"#\" for next word):\n");
        printf("> ");
        scanf("%s", input);
        // quit the searching part
        if (feof(stdin) || strcmp(input, "exit") == 0) {
            break;
        } else if (input[0] == '#') {
            p_counter++;
            int counter = 1;
            while (counter < strlen(input)) {
                if (input[counter] == '#') {
                    p_counter++;
                }
                counter++;
            }
            if (cur) {
                while (p_counter > 0 && cur) {
                    cur = cur->next;
                    p_counter--;
                }
            }
            if (cur) {
                printf("\t\'%s'\n", cur->str);
                p_counter = 0;
            } else {
                p_counter = 0;
                printf("\tThere are no more T9onyms\n");
            }
        } else {   // trace down the trie to find word
            for (int i = 0; i < strlen(input); i++) {
                int pos = input[i] - '0';
                pos = pos - 2;
                if (pos >= 0 && pos <= 7) {
                    if (!runner->list[pos]) {
                        break;
                    }
                    runner = runner->list[pos];
                    cur = runner->res_word;
                } else if (input[i] == '#') {
                    if (cur) {
                        cur = cur->next;
                    } else {
                        flag = 1;
                        break;
                    }
                } else {
                    printf("\tInvalid Input\n");
                    invalid = 1;
                    break;
                }
            }
            if (cur && invalid == 0 && flag == 0) {
                printf("\t\'%s\'\n", cur->str);
            } else if (flag == 0 && invalid == 0) {
                printf("\tNot found in current dictionary\n");
            } else {
                if (invalid == 0) {
                    printf("\tThere are no more T9onyms\n");
                }
            }
        }
        flag = 0;  // reset flag
        invalid = 0;
        runner = root;
    }
}
