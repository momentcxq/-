# include <stdlib.h>
typedef long Align;				/* for alignment to long boundary */
union header {					/* block header: */
	struct {
		union header *next;		/* next block if on Free list */
		unsigned int size;		/* size of this block */
	} s;
	Align x;					/* force alignment of blocks */
};
typedef union header Header;

# define NALLOC 10				/* minimum #units to request */
static Header* morecore(unsigned int nu);
void* Malloc(unsigned int nbytes);
void Free(void *ap);
