#include <kbtree.h>
#include <stdlib.h>
#include <stdio.h>

typedef int key_t;

KBTREE_INIT(test, key_t, kb_generic_cmp);

#define N 1000

int
main(int argc, char **argv)
{
kbtree_t(test) *kb = kb_init(test, 64);
int             i;
kbitr_t         it, it1;
int             v0,v1;
int             rval = 1;

	for ( i=0; i<N; i++ ) {
		do {
			v0 = rand();
		} while ( kb_get(test, kb, v0) );
		
		kb_put(test, kb, v0);
	}

	i = 0;
	kb_itr_first(test, kb, &it);

	if ( ! kb_itr_valid( &it ) ) {
		fprintf(stderr, "Test FAILED -- first iterator invalid\n");
		goto bail;
	}

	i  = 1;
	v0 = kb_itr_key(key_t, &it );
	kb_itr_next(test, kb, &it );

	while ( kb_itr_valid( &it ) ) {
		v1 = kb_itr_key(key_t, &it );	
		if ( v1 <= v0 ) {
			fprintf(stderr, "Test FAILED -- found out-of-order element\n");
			goto bail;
		}
		if ( kb_itr_get(test, kb, &v0, &it1) ) {
			fprintf(stderr, "Test FAILED -- kb_itr_get() on existing key failed\n");
			goto bail;
		}
		if ( kb_itr_key(key_t, &it1) != v0 ) {
			fprintf(stderr, "Test FAILED -- kb_itr_get() found mismatching key\n");
			goto bail;
		}
		v1 = v0;
		i++;
		kb_itr_next(test, kb, &it);
	}

	if ( i != N ) {
		fprintf(stderr, "Test FAILED -- only %i iterations (expected %i)\n", i, N);
		goto bail;
	}

	fprintf(stderr,"Test PASSED\n");
	rval = 0;

bail:
	kb_destroy(test, kb);

	return rval;
}
