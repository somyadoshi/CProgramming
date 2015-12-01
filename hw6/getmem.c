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
    block* prev;
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
            newBlock = (block*)malloc(reqSize + headerSize);
            newBlock->size = reqSize;
            newBlock->next = NULL;
            return (void*)((uintptr_t)newBlock + headerSize);        
        } else {  // malloc defualt space and insert it into freelist, search again
            requestMoreSize(MoreSize);            
            res = searchFreeBlock(reqSize);
        }
    }
    //get previous block before 
    runner = FREE_LIST;
    while(runner && runner->next) {
        if(runner->next == res) {
            prev = runner;
            break;
        } else {
            runner = runner->next;
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
        prev->next = newBlock;  // add the new block into the free list
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
    SortFreeList();
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

// request a big block from malloc and insert it in front of the free list
void requestMoreSize() {
    block* tmp;
    block* runner;
    tmp = (block*)malloc(MoreSize + headerSize);
    tmp->size = MoreSize;
    tmp->next = NULL;
    if(!FREE_LIST) {
        FREE_LIST = tmp;
    } else {
        runner = FREE_LIST;
        // front case
        if(tmp < runner) { 
            tmp->next = runner;
            FREE_LIST = tmp;
        } else {  // the new block will either be in the front or the back
            while(runner && runner->next) {
                runner = runner->next;
            }
            runner->next = tmp;
        }
    }
}

// insertion sort to sort the single linked list
void SortFreeList() {
    // length is 1 or 0, no need to sort
    if(!FREE_LIST || !FREE_LIST->next) {
        return;
    block* head = FREE_LIST->next;
    head->next = NULL;
    block* insertion;
    block* runner;
    }
}
