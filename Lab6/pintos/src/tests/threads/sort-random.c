#include <stdio.h>
#include <stdlib.h>
#include <kernel/list.h>
#include "threads/thread.h"
#include <random.h>
#include "devices/timer.h"

//using list.h
struct ele{
    struct list_elem elem;
    int x;
}*x;

static bool value_less (const struct list_elem *a_, const struct list_elem *b_, void *aux UNUSED) 
{
  const struct ele *a = list_entry (a_, struct ele, elem);
  const struct ele *b = list_entry (b_, struct ele, elem);
  return a->x < b->x;
}
static void listsort(void * aux UNUSED)
{
    printf("asdf");
    thread_set_nice (20);
    struct list list;
    x=(struct ele *)malloc(10*sizeof(struct ele));
    int i;
    list_init(&list);
    for(i=0;i<10;i++)
    {
        random_bytes(&x[i].x,sizeof(int));
        list_push_back(&list,&x[i].elem);
    }
    
    list_sort (&list,value_less,NULL);
    struct list_elem *e;
    for (e = list_begin (&list); e != list_end (&list);e = list_next (e))
    {
          struct ele *f = list_entry (e, struct ele, elem);
          printf("%d ",f->x);
    }
    printf("\n");
    free(x);
}

void test_sort_random(void)
{
    thread_create("high",PRI_DEFAULT + 3,listsort,NULL);
    thread_yield();
}


