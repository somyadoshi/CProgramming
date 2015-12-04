//Wenlu Cheng
//Donglan Ni
#ifndef MEM_IMPL_H
#define MEM_IMPL_H
#define MoreSize 8016
#define headerSize 16
#define threshold 64

struct block {
    // size and tag
    uintptr_t size;
    // pointer to next block
    struct block* next;
    // pointer to previous block
};

typedef struct block block;
uintptr_t total_mallocsize;  //variable to store total malloc size 
block* FREE_LIST;  // free list to hold all freed block

void* searchFreeBlock(uintptr_t size);
void requestMoreSize();
void coalesce(block* block1, block* block2);
void* searchFreeBlock(uintptr_t size);
void requestMoreSize();
void insertFreeBlock(block* freeBlock);
#endif
