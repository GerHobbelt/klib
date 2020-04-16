#include <kbtree.h>
#include <stdlib.h>
#include <stdio.h>

typedef int key_t;

KBTREE_INIT(test, key_t, kb_generic_cmp);

#define N 1000

static int kb_itr_cmp(kbitr_t *a, kbitr_t *b)
{
int na, nb, i;
int rval;

	na = a->p - a->stack + 1;
	nb = b->p - b->stack + 1;

	if ( na != nb ) {
		fprintf(stderr, "iterator A has %i elements on stack, iterator B has %i elements\n", na, nb);
		return -1;
	}

	rval = 0;
	for ( i = 0; i < na; i++ ) {
		if ( a->stack[i].x != b->stack[i].x ) {
			fprintf(stderr, "iterator A.stack[%i].x != iterator B.stack[%i].x (depth %i)\n", i, i, na);
			rval = -1;
		}
		if ( a->stack[i].i != b->stack[i].i ) {
			fprintf(stderr, "iterator A.stack[%i].i (%i) != iterator B.stack[%i].i (%i) (depth %i)\n", i, a->stack[i].i, i, b->stack[i].i, na);
			rval = -1;
		}
	}

	return rval;
}

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
		/* verify that element is bigger than the previous one */
		v1 = kb_itr_key(key_t, &it );	
		if ( v1 <= v0 ) {
			fprintf(stderr, "Test FAILED -- found out-of-order element\n");
			goto bail;
		}
		i++;

		/* test kb_itr_get() */
		if ( kb_itr_get(test, kb, &v1, &it1) ) {
			fprintf(stderr, "Test FAILED -- kb_itr_get() on existing key failed\n");
			goto bail;
		}
		if ( ! kb_itr_valid( &it1 ) ) {
			fprintf(stderr, "Test FAILED -- kb_itr_get() returned invalid iterator\n");
			goto bail;
		}
		if ( kb_itr_key(key_t, &it1) != v1 ) {
			fprintf(stderr, "Test FAILED -- kb_itr_get() found mismatching key\n");
			goto bail;
		}

		/* Verify iterator equality */
		if ( kb_itr_cmp( &it, &it1 ) ) {
			fprintf(stderr, "Test FAILED -- kb_itr_get() returned different iterator (element %i)\n", i);
			goto bail;
		}

		v0 = v1;
		kb_itr_next(test, kb, &it);
	}

	if ( i != N ) {
		fprintf(stderr, "Test FAILED -- only %i iterations (expected %i)\n", i, N);
		goto bail;
	}

	v0 = -4;
	if ( 0 == kb_itr_get(test, kb, &v0, &it1 ) ) {
		fprintf(stderr, "Test FAILED -- kb_itr_get() for non-existing key returned 0\n");
		goto bail;
	}

	fprintf(stderr,"Test PASSED\n");
	rval = 0;

bail:
	kb_destroy(test, kb);

	return rval;
}
