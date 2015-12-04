# Wenlu Cheng, Donglan Ni
# hw6 make file 

bench: getmem.o freemem.o check_heap.o get_mem_stats.o print_heap.o bench.o 
	gcc -std=c99 -Wall -g -o bench bench.o check_heap.o getmem.o freemem.o get_mem_stats.o print_heap.o

bench.o: bench.c mem.h 
		gcc -std=c99 -Wall -g -c bench.c

#test: getmem.o freemem.o get_mem_stats.o print_heap.o test.o 
#	gcc -std=c99 -Wall -g -o test test.o getmem.o freemem.o get_mem_stats.o print_heap.o

#test.o: test.c mem.h 
#		gcc -std=c99 -Wall -g -c test.c
check_heap.o: check_heap.c mem_impl.h
		gcc -std=c99 -Wall -g -c check_heap.c

freemem.o: freemem.c mem_impl.h 
		gcc -std=c99 -Wall -g -c freemem.c

getmem.o: getmem.c mem_impl.h
		gcc -std=c99 -Wall -g -c getmem.c

print_heap.o: print_heap.c mem_impl.h 
		gcc -std=c99 -Wall -g -c print_heap.c

get_mem_stats.o: get_mem_stats.c mem_impl.h 
		gcc -std=c99 -Wall -g -c get_mem_stats.c

dist: bench
		git log > ./git.log
			tar vcf hw6.tar ./*.c ./*.h ./README.md ./git.log ./Makefile
clean:
		rm -f *.o *~ git.log test hw6.tar bench
