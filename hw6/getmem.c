// Wenlu Cheng, Donglan Ni
// HW 6
// This file contains the method of allocating memory block

#include "mem.h"
#include "mem_impl.h"

// get a block of required size and return it
// if the required size is too big, malloc more size and insert that into freelist
void* getmem(uintptr_t size) {
    block* res;  // result block that will be returned
    block* runner;  // modify the list
    block* newBlock;  // spilited block
    uintptr_t reqSize;  // actual size need to malloc
    if(size <= 0) {
        return NULL;
    }
    if(size % 16 != 0) {
       reqSize = ((size / 16) + 1) * 16;
    }
    //search for the free block
    res = searchFreeBlock(reqSize);
    if(!res) {  // did not get the block
    // if the required size is more than default malloc size
        if(reqSize > MoreSize + headerSize) {
            res = (block*)malloc((int)reqSize + headerSize);
            res->size = reqSize;
            res->next = NULL;
            return (void*)((uintptr_t)res + headerSize);
        } else {  // malloc defualt space and insert it into freelist, search again
            requestMoreSize();            
            res = searchFreeBlock(reqSize);
        }
    }
    // get one block from freelist, now check if that block need to be divived or not
    // if res->size > reqSize + hearSize, we need to spilit the block
    if(res->size > (reqSize + headerSize)) {
        // spilit the block
        newBlock = (block*) ((uintptr_t)res + headerSize + reqSize);
        // thresold value
        newBlock->size = res->size - headerSize - reqSize;
        newBlock->next = res->next;
        res->size = reqSize;
        res->next = NULL;
    } else {
        // remove the block from freelist if res->size = reqSize + headerSize
        runner = FREE_LIST;
        while(runner && runner->next) {
            if(runner->next == res) {
                runner->next = runner->next->next;
            } else {
                runner = runner->next;
            }
        }
    }
    return (void*)((uintptr_t)res + headerSize);
}


// search for free block list and return the first matached block back
void* searchFreeBlock(uintptr_t size) {
    block* freeBlock;
    freeBlock = FREE_LIST;
    while(freeBlock != NULL) {
        if(freeBlock->size >= size) {
            return (void*)((uintptr_t)freeBlock + headerSize);
        } else {
            freeBlock = freeBlock->next;
        }
    }
    return NULL;
}

void requestMoreSize() {
    block* tmp;
    tmp = (block*)malloc(MoreSize + headerSize);
    tmp->size = MoreSize;
    tmp->next = NULL;
    freemem(tmp);
}
