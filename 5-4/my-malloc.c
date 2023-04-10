# include <unistd.h>
# include "my-malloc.h"

static Header base;						/* empy list to get started */
static Header* free_list = NULL;		/* start of free list */

//定义Malloc函数：分配一块内存空间
void* Malloc(unsigned int nbytes)
{
	Header *p, *prev;
	unsigned int nunits;
	nunits = (nbytes + sizeof(Header) -1) / sizeof(Header) + 1;
	if ((prev=free_list) == NULL)		// no free list yet //
	{				// 没有节点
		base.s.next=free_list=prev=&base;
		base.s.size=0;
	}
	for (p=prev->s.next;;prev=p,p=p->s.next)
	{
		if (p->s.size>=nunits){			// big enough
			if (p->s.size==nunits)		// exactly
				prev->s.next=p->s.next;
			else {
				p->s.size-=nunits;
				p+=p->s.size;
				p->s.size=nunits;
			}
			free_list=prev;
			return(void*)(p+1);
		}
		if(p==free_list)					/* wrapped around Free list */
			if((p=morecore(nunits))==NULL)	/* 如果系统不提供新的内存空间，则返回NULL */
				return NULL;				/* none left */
	}										/* endfor */
}

// 向系统申请足够大的一块空间
static Header* morecore(unsigned int nu){
	char  *cp;
	Header *up;

	if(nu<NALLOC)
		nu=NALLOC;
	cp=sbrk(nu * sizeof(Header));
	printf("sbrk:%X--%X\n",cp,cp+nu * sizeof(Header));
	if(cp==(char*)-1)						// 没有空间则返回NULL
		return NULL;
	up=(Header*)cp;
	up->s.size=nu;
	Free(up+1);
	return free_list;
}

//put block ap in Free list
void Free(void* ap)
{
	Header *bp,*p;
	bp=(Header*)ap-1;							/* point to block header */
	for(p=free_list;!(bp>p&&bp<p->s.next);p=p->s.next)
		if(p>=p->s.next&&(bp>p||bp<p->s.next))
			break;								// freed block at start or end of arena
		if(bp+bp->s.size==p->s.next){			// 如果新申请的空闲空间和另一空闲空间邻接则合并
			bp->s.size+=p->s.next->s.size;
			bp->s.next=p->s.next->s.next;
		}
		else
			bp->s.next=p->s.next;
		if(p+p->s.size==bp){
			p->s.size+=bp->s.size;
			p->s.next=bp->s.next;
		}  
		else
			p->s.next=bp;
		free_list=p;
}

// 打印分配给用户的空闲块链表
void printlist(void)
{
	Header *p;
	int i=0;
	printf("base:%X, base.next:%X, base.next.next:%X\n", &base,base.s.next, base.s.next->s.next,free_list);
	for(p=&base; p->s.next!=free_list; p=p->s.next)
	{
		i++;
		printf("block%d,size=%d",i,p->s.size);
		if (p>free_list)
			printf("used!\n");
		else
			printf("free!\n");
	}
}

int main()
{
    char *p[200];
	int i;
	
	for (i=0;i<20;i++)
	{
		p[i]=(char *) Malloc(8);
		printf("malloc %d, %X\n", i, p[i]);
		printlist();
	}
	for (i=19; i>=0; i--)
	{
		Free(p[i]);
		printf("free %d \n", i);
		printlist();
	}
    return 0;
}