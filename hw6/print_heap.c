// Wenlu Cheng, Donglan Ni
// HW 6
// Print a formatted listing on file f showing the blocks on the free list.

#include "mem.h"
#include "mem_impl.h"

void print_heap(FILE * f){
  block* runner = FREE_LIST;
  while (runner != NULL) {
    fprintf(f, "address: %p size: ", runner);
    fprintf(f, "%" PRIdPTR "\n", runner->size);
    runner = runner->next;
  }
  fclose(f);
}
