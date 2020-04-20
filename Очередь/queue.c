#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define QSIZE 105
typedef struct queue
{
    int container[QSIZE];
    int head,tail;
}queue;

void qu_init(queue *qu)
{
    qu->head = 1;
    qu->tail = 0;
}


int qu_size(queue *qu)
{
    return (qu->tail-qu->head)+1;
}

void qu_push(queue *qu,int n)
{
    if (qu->tail<QSIZE-1)
    {
        qu->tail++;
        qu->container[qu->tail] = n;
        printf("ok\n");
    }else
    {
        printf("error\n");
    }
}

void qu_pop(queue *qu)
{
    int a;
    if (qu->tail < qu->head)
    {
        printf("error\n");
        return;
    }
    a = qu->container[qu->head];
    for (int i=qu->head;i<qu->tail;i++)
    {
        qu->container[i] = qu->container[i+1];
    }
    qu->tail--;
    printf("%i\n",a);

}

void qu_front(queue *qu)
{
    if (qu_size(qu))
    {
        printf("%i\n",qu->container[qu->head]);
    }else
    {
        printf("error\n");
    }
}


int main(void)
{
    queue q;
    qu_init(&q);
    char command[5];
    do
    {
        scanf("%s",command);
        if (!strcmp(command,"push"))
        {
            int n;
            scanf("%i",&n);
            qu_push(&q,n);
        }else if (!strcmp(command,"pop"))
        {
            qu_pop(&q);
        }else if (!strcmp(command,"front"))
        {
            qu_front(&q);
        }else if (!strcmp(command,"size"))
        {
            printf("%i\n",qu_size(&q));
        }else if (!strcmp(command,"clear"))
        {
            qu_init(&q);
            printf("ok\n");
		}
    } while (strcmp(command,"exit"));
    printf("bye\n");
    return 0;
}