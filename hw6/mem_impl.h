//Wenlu Cheng
//Donglan Ni
#ifndef MEM_IMPL_H
#define MEM_IMPL_H
#define MoreSize 8016
#define headerSize 16
#define threshold 64

<<<<<<< HEAD
struct block {
=======
block {
>>>>>>> 6bc4853ddedd2c5867ee1c06073a818cc07d3a14
    // size and tag
    uintptr_t size;
    // pointer to next block
    struct block* next;
    // pointer to previous block
};

typedef struct block block;

block* FREE_LIST;  // free list to hold all freed block

<<<<<<< HEAD
void coalesce(block* block1, block* block2);
void* searchFreeBlock(uintptr_t size);
void requestMoreSize();
=======
block* coalesce(block* block);
void* searchFreeBlock(uintptr_t size);
void requestMoreSize(uintptr_t size);

>>>>>>> 6bc4853ddedd2c5867ee1c06073a818cc07d3a14
#endif
