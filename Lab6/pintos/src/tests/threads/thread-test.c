#include <stdio.h>
#include <stdlib.h>
#include "threads/thread.h"
#define loops 10000
void test_thread(void);

static void printName(void * aux UNUSED)
{
    int i,j,k;
    //for(i=0;i<100;i++)
    {
        thread_print_stats();
        for(k=0;k<loops;k++)
            for(j=0;j<loops;j++);
        thread_print_stats();
    }
}

static void printId(void * aux UNUSED)
{
    int i,j,k;
    //for(i=0;i<100;i++)
    {
        thread_print_stats();
        for(k=0;k<loops+5000;k++)
            for(j=0;j<loops+5000;j++);
        thread_print_stats();
    }
}

static void printPriority(void * aux UNUSED)
{
    int i,j,k;
    //for(i=0;i<100;i++)
    {
        thread_print_stats();
        for(k=0;k<loops-5000;k++)
            for(j=0;j<loops-5000;j++);
        thread_print_stats();
    }
}

void test_thread(void)
{
    thread_create("high",PRI_DEFAULT + 11,printName,NULL);
    thread_create("sec",PRI_DEFAULT + 6,printId,NULL);
    thread_create("thir",PRI_DEFAULT + 3,printPriority,NULL);
    raja_ticks_counter=0;
    int i,j,k;
    //for(i=0;i<100;i++)
    {
        printf("main thread (%lld) : %d\n",raja_ticks_counter,i);
        thread_print_stats();
        for(k=0;k<loops;k++)
            for(j=0;j<loops;j++);
        thread_print_stats();
    }
    //timer_sleep (100);
}

//using list.h
struct ele{
    struct list_elem elem;
    int x;
}*x;
struct list list;

static bool value_less (const struct list_elem *a_, const struct list_elem *b_, void *aux UNUSED) 
{
  const struct ele *a = list_entry (a_, struct ele, elem);
  const struct ele *b = list_entry (b_, struct ele, elem);
  return a->x < b->x;
}

static void genRand(void *aux UNUSED)
{
    thread_set_nice (20);
    x=(struct ele *)malloc(10*sizeof(struct ele));
    int i;
    list_init(&list);
    for(i=0;i<10;i++)
    {
        random_bytes(&x[i].x,sizeof(int));
        list_push_back(&list,&x[i].elem);
    }
}

static void sortUsingList(void *aux UNUSED)
{
    list_sort (&list,value_less,NULL);
}

static void display(void *aux UNUSED)
{
    struct list_elem *e;
    for (e = list_begin (&list); e != list_end (&list);e = list_next (e))
    {
          struct ele *f = list_entry (e, struct ele, elem);
          printf("%d ",f->x);
    }
    printf("\n");
    free(x);
}

void test_thread_sort(void)
{
    thread_create("high",PRI_DEFAULT + 11,genRand,NULL);
    thread_create("high",PRI_DEFAULT + 6,sortUsingList,NULL);
    thread_create("high",PRI_DEFAULT + 3,display,NULL);
}


