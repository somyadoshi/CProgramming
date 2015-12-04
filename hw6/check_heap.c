// Wenlu Cheng, Donglan Ni
// HW 6
// This file check for possible problems with the free list data structure


#include "mem.h"
#include "mem_impl.h"
#include <assert.h>
void check_heap() {
  block* prev = FREE_LIST;
  if (FREE_LIST != NULL) {
    block* next = prev->next;
    while (next != NULL) {
      assert(prev < next);
      assert(prev->size > 0 && prev->size >= threshold);
    }
  }
}
