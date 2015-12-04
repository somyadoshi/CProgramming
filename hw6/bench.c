// Wenlu Cheng, Donglan Ni                                                                        
// HW 6                                                                                           
// This file is the bench file, it allocate the memory and free the allocated blocks              
// with random size in random order.                                                              

#include "mem.h"
#include <time.h>
#include <stdio.h>  //null     
#include <stdlib.h>  //rand                                                                     

uintptr_t* mem;
clock_t start_t, end_t;

void runMem(int arg[]) {
  int ntrials = arg[0];
  int pctget = arg[1];
  int pctlarge = arg[2];
  int small_limit = arg[3];
  int large_limit = arg[4];
  int random_seed = arg[5];

  srand(random_seed);
  int getOrFree = 0;
  int blocksize = 0;
  int smallOrLarge;
  int memnumber = 0;
  int freenumber = 0;
  uintptr_t total_free = 0;
  uintptr_t n_free_blocks = 0;
  uintptr_t total_size = 0;
  mem = (uintptr_t*)malloc(ntrials*sizeof(uintptr_t));
    
  for (int i = 0; i < ntrials; i++) {
    getOrFree = rand() % 100;
    if (getOrFree < pctget) {  /* getmem */
      smallOrLarge = rand() % 100;
      if (smallOrLarge < pctlarge) {
	blocksize = rand() % large_limit + small_limit;
      } else {
        blocksize = rand() % small_limit + 1;
      }
      uintptr_t temp = (uintptr_t)getmem(blocksize);
      printf("pointer from getmem:%lu\n", (uintptr_t)getmem(blocksize));
      mem[memnumber] = temp;
      printf("getmem:%d %lu\n", memnumber+1, mem[memnumber]);
      memnumber++;
    } else {  /* freemem */
      freenumber++;
      //printf("current mem number: %d\n", memnumber);
      //if there are available allocated blocks in array
      if (memnumber > 0) {
        if (memnumber > 1) {
	  int blocktoFree = rand() % memnumber;
          freemem((uintptr_t*) mem[blocktoFree]);
	  //printf("free: %lu\n", mem[blocktoFree]);
	  mem[blocktoFree] = mem[memnumber-1];
	  //printf("mem address: %lu\n", mem[blocktoFree]);
	  mem[memnumber-1] = 0;
	  //printf("last mem: %lu\n", mem[memnumber-1]);
        } else {
          freemem((uintptr_t*) mem[0]);
	  printf("free: %lu\n", mem[0]);
	  mem[0] = 0;
        }
	memnumber= memnumber - 1;
	//printf("current mem number: %d\n", memnumber);
      }
    }
    //prinf running details to stdout
    if ( (i + 1) % 10 == 0) {
      end_t = clock();
      double total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
      printf("CPU time: %lf\n", total_t);
      get_mem_stats(&total_size, &total_free, &n_free_blocks);
      printf("current free storage: %lu\n", n_free_blocks);
      printf("total storage acquired from malloc: %lu\n", total_size);
      printf("average number of bytes in free mem blocks: %lu\n",
	     (total_free / n_free_blocks));
    }
  }
}

int main (int argc, char* argv[]) {
  start_t = clock();
  FILE * f;
  f = fopen("output.txt", "w");
  int arg[6];
  arg[0] = 10000;
  arg[1] = 50;
  arg[2] = 10;
  arg[3] = 200;
  arg[4] = 20000;
  //arg[5] = 1449160315;
  arg[5] = time(NULL);                                                                        
  printf("%d\n", arg[5]);
  if (argc > 1) {
    for (int i = 1; i < argc; i++) {
      //convert to decimal integers                                                             
      arg[i-1] = atoi(argv[i]);
     }
   }
   runMem(arg);
   print_heap(f);
   check_heap();
}
