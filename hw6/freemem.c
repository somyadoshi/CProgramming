// Wenlu Cheng, Donglan Ni
// HW 6
// This file includes method of freeing an block

#include "mem.h"
#include "mem_impl.h"


void freemem(void* p){
    block* runner = FREE_LIST;
    block* freeBlock = p - headerSize;
    if(!p){
        return;
    }
    // if the whole list is null, add the block into the list and return
    if(!runner){
        FREE_LIST = p;
        return;
    }
    // add the freeBlock at the front if it is front case
    if(runner && freeBlock < runner){
        freeBlock->next = runner;
        FREE_LIST = freeBlock;
        return;
    }
    // when the list is not empty
    while(runner && runner->next && runner->next < freeBlock){
        runner = runner->next;
    }
    // reach the end, add the block at the end
    if(!runner->next){
        runner->next = freeBlock;
        return;
    }else{
        // add the block into the list
        freeBlock->next = runner->next;
        runner->next = freeBlock;
    }
    // now  coalesceFreeBlock
    runner = FREE_LIST;
    while(runner && runner->next){
        if((uintptr_t)runner + (uintptr_t)runner->size + headerSize == (uintptr_t)runner->next){
            coalesce(runner, runner->next); 
        }else{
            runner = runner->next;
        }
    }
}

// return a coalesced block if two blocks are adjacent
void coalesce(block* block1, block* block2){
    block1->size = (uintptr_t)block1->size + (uintptr_t)block2->size + headerSize;
    block1->next = block2->next;
}

