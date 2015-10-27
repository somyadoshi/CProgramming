// Wenlu Cheng, HW4, CSE 374
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// define the max line reading and max line input string
#define MaxLine 500
#define MaxStr 100

int contains(char line[], char target[]);
void open_file(char file[], char target[], int case_ignore, int p_line);

// check the argument number first,then check if there is
// additional options, if there is, mark the flag varaible and then
// open file and start to search
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: gasp -options String File\n");
        return -1;
    }
    int case_ignore = 0, p_line = 0;
    // match the option given on the command line, start from 1
    for (int i = 1; i < argc && argv[i][0] == '-'; i++) {
        if (argv[i][1] == 'i') {
            case_ignore = 1;   // mark the case flag
        } else if (argv[i][1] == 'n') {
            p_line = 1;   // mark the print line number flag
        } else {   // else the option is not valid
            printf("Invalid Option\n");
            return -1;
        }
    }
    // open file with given file name and start to search target string
    open_file(argv[argc - 1], argv[argc - 2], case_ignore, p_line);
}


// string to lower, take old string and make it lowercase
void toLowerCase(char * old, char * new) {
    for (int i = 0; old[i]; i++) {
        new[i] = tolower(old[i]);
    }
}

// process a single file
void open_file(char file[], char target[], int case_ignore, int p_line) {
    FILE *fr;
    char line[MaxLine];  // input line
    char line_case[MaxLine];  // new case-ignored string
    int line_num = 1;   // default line number
    int has_target = 0;  // use as a bool to check if the string has target
    fr = fopen(file, "rt");
    // if the file doesnt open correctly
    if (fr == NULL) {
        perror("File does not exist");
        exit(EXIT_FAILURE);
    }
    while (fgets(line, MaxLine, fr) != NULL) {
        line_num++;
        if (case_ignore == 1) {
            strncpy(line_case, line, sizeof(line));  // copy the line
            toLowerCase(line_case, line_case);   // make the copy to lower case
            toLowerCase(target, target);   // make the target to lowercase
            has_target = contains(line_case, target);
        } else {
            has_target = contains(line, target);
        }
        // return -1 if there is no match
        // otherwise renturn a number greater than 0
        if (has_target != 0) {
            if (p_line == 1) {
                printf("%s %d %s", file, line_num, line);
            } else {
                printf("%s", line);
            }
        }
    }
    fclose(fr);
}

// find target string in line, if found, return 1, otherwise return 0
int contains(char line[], char target[]) {
    if (strstr(line, target) != NULL) {
        return 1;
    } else {
        return 0;
    }
}
