// Wenlu Cheng, Donglan Ni
// hw6
// header for memory manager

#include<stdio.h>
#include<stdlib.h>

void* getmem (uintptr_t size);
void freemem (void *ptr);
void get_mem_stats(uintptr_t* total_size, uintptr_t* total_free, uintptr_t* n_free_blocks);
void print_heap(FILE* f);
void check_heap();

