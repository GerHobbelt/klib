CC=gcc
CXX=g++
CFLAGS=-g -Wall -O2 -I..
CXXFLAGS=$(CFLAGS)
PROGS=kbtree_test khash_keith khash_keith2 khash_test klist_test kseq_test kseq_bench \
		kseq_bench2 ksort_test ksort_test-stl kvec_test kmin_test kstring_bench kstring_bench2 kstring_test \
		kavl_test kavl-lite_test kthread_test2 kbitset_test kbtree_itr_test

all:$(PROGS)

clean:
		rm -fr $(PROGS) *.dSYM a.out *.o

kavl_test:kavl_test.c ../kavl.h
		$(CC) $(CFLAGS) -o $@ kavl_test.c

kavl-lite_test:kavl-lite_test.c ../kavl-lite.h
		$(CC) $(CFLAGS) -o $@ kavl-lite_test.c

kbtree_test:kbtree_test.c ../kbtree.h
		$(CC) $(CFLAGS) -o $@ kbtree_test.c

kbtree_itr_test:kbtree_itr_test.c ../kbtree.h
		$(CC) $(CFLAGS) -o $@ $<

khash_keith:khash_keith.c ../khash.h
		$(CC) $(CFLAGS) -o $@ khash_keith.c

khash_keith2:khash_keith2.c ../khash.h
		$(CC) $(CFLAGS) -o $@ khash_keith2.c

khash_test:khash_test.c ../khash.h
		$(CC) $(CFLAGS) -o $@ khash_test.c

klist_test:klist_test.c ../klist.h
		$(CC) $(CFLAGS) -o $@ klist_test.c

kseq_test:kseq_test.c ../kseq.h
		$(CC) $(CFLAGS) -o $@ kseq_test.c -lz

kseq_bench:kseq_bench.c ../kseq.h
		$(CC) $(CFLAGS) -o $@ kseq_bench.c -lz

kseq_bench2:kseq_bench2.c ../kseq.h
		$(CC) $(CFLAGS) -o $@ kseq_bench2.c -lz

ksort_test:ksort_test.c ../ksort.h
		$(CC) $(CFLAGS) -o $@ ksort_test.c

ksort_test-stl:ksort_test.cc ../ksort.h
		$(CXX) $(CXXFLAGS) -o $@ ksort_test.cc

kvec_test:kvec_test.cc ../kvec.h
		$(CXX) $(CXXFLAGS) -o $@ kvec_test.cc

kmin_test:kmin_test.c ../kmath.h ../kmath.c
		$(CC) $(CFLAGS) -o $@ kmin_test.c ../kmath.c -lm

kstring_bench:kstring_bench.c ../kstring.h ../kstring.c
		$(CC) $(CFLAGS) -o $@ kstring_bench.c ../kstring.c

kstring_bench2:kstring_bench2.c ../kstring.h ../kstring.c
		$(CC) $(CFLAGS) -o $@ kstring_bench2.c ../kstring.c

kstring_test:kstring_test.c ../kstring.h ../kstring.c
		$(CC) $(CFLAGS) -o $@ kstring_test.c ../kstring.c

kthread_test:kthread_test.c ../kthread.h ../kthread.c
		$(CC) $(CFLAGS) -fopenmp -o $@ kthread_test.c ../kthread.c -lpthread

kthread_test2:kthread_test2.c ../kthread.h ../kthread.c
		$(CC) $(CFLAGS) -o $@ kthread_test2.c ../kthread.c -lpthread

kbitset_test:kbitset_test.c ../kbitset.h
		$(CC) $(CFLAGS) -o $@ kbitset_test.c

ketopt_test:ketopt_test.c ../ketopt.h
		$(CC) $(CFLAGS) -o $@ ketopt_test.c
