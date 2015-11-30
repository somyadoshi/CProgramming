// Wenlu Cheng, Donglan Ni
// hw6
// header for memory manager

#ifndef MEM_H
#define MEM_H

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdint.h>

void* getmem (uintptr_t size);
void freemem (void *ptr);
void get_mem_stats(uintptr_t* total_size, uintptr_t* total_free, uintptr_t* n_free_blocks);
void print_heap(FILE* f);
void check_heap();

#endif
