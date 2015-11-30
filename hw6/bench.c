// Wenlu Cheng, Donglan Ni
// HW 6
// This file is the bench file, it allocate the memory and free the allocated blocks
// with random size in random order.

#include "mem.h"


int main(int argc, char* argv[]){
    char* test = getmem(100);
    freemem(test);
}
