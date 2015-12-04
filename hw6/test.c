#include "mem.h"

int main(int argc, char** argv) {
    FILE *f = fopen("test.txt", "w");
    void* test1 = getmem(100);
    void* test2 = getmem(16);
    freemem(test2);
    void* test3 = getmem(2000);
    void* test4 = getmem(7000);
    freemem(test3);
    void* test5 = getmem(500);
    freemem(test1);
    void* test7 = getmem(200000);
    freemem(test7);
    void* test8 = getmem(10000);
    print_heap(f);
}
