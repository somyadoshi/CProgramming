// Wenlu Cheng, Donglan Ni
// HW 6
// This file contains method of getting the stats of memory


#include "mem.h"
#include "mem_impl.h"

void get_mem_stats(uintptr_t* total_size, uintptr_t* total_free, uintptr_t* n_free_blocks){
  *total_size = total_mallocsize;
  block* temp = FREE_LIST;
  while (temp != NULL) {
    *total_free += temp->size;
    *n_free_blocks += 1;
    temp = temp->next;
  }
}
