#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NSIZE 105

typedef struct deque
{
    int front;
    int back;
    int container[NSIZE];

}deque;

void dq_init(deque *dq)
{

    dq->front = 0;
    dq->back = 0;
}

int dq_size(deque *dq)
{
    if (dq->front == dq->back)
    {
        return 0;
    }else if (dq->front < dq->back)
    {
        return (dq->back - dq->front);
    }else
    {
        return (dq->back+NSIZE - dq->front);
    }
}

void dq_push_back(deque *dq, int n)
{
    //dq->container[dq->back++] = n;
    if (dq->front != (dq->back+1) % NSIZE)
    {
        dq->container[dq->back] = n;
        dq->back = (dq->back+1)%NSIZE;
        printf("ok\n");
    }
}

void dq_pop_back(deque *dq)
{
    if (!dq_size(dq))
    {
        printf("error\n");
        return;
    }
    dq->back = (dq->back-1+NSIZE)%NSIZE;
    printf("%i\n",dq->container[dq->back]);
}

void dq_push_front(deque *dq,int n)
{
    if (dq->front != (dq->back+1) % NSIZE)
    {
        dq->front=(dq->front-1+NSIZE)%NSIZE;
        dq->container[dq->front] = n;
        printf("ok\n");
    }
}

void dq_pop_front(deque *dq)
{
    if (!dq_size(dq))
    {
        printf("error\n");
        return;
    }
    printf("%i\n",dq->container[dq->front]);
    dq->front = (dq->front+1)%NSIZE;
}

void dq_back(deque *dq)
{
    if (dq_size(dq))
    {
        printf("%i\n",dq->container[(dq->back-1)%NSIZE]);
    }else
    {
        printf("error\n");
    }
}

void dq_front(deque *dq)
{
    if (dq_size(dq))
    {
        printf("%i\n",dq->container[dq->front]);
    }else
    {
        printf("error\n");
    }

}



/*
int main(void)
{
    deque dq;
    dq_init(&dq);
    char command[10];
    int n;
    do
    {
        scanf("%s",command);
        if (!strcmp(command,"push_front"))
        {
            scanf("%i",&n);
            dq_push_front(&dq,n);
        }else if (!strcmp(command,"push_back"))
        {
            scanf("%i",&n);
            dq_push_back(&dq,n);
        }else if (!strcmp(command,"pop_front"))
        {
            dq_pop_front(&dq);
        }else if (!strcmp(command,"pop_back"))
        {
            dq_pop_back(&dq);
        }else if (!strcmp(command,"front"))
        {
            dq_front(&dq);
        }else if (!strcmp(command,"back"))
        {
            dq_back(&dq);
        }else if (!strcmp(command,"size"))
        {
            printf("%i\n",dq_size(&dq));
        }else if (!strcmp(command,"clear"))
        {
            dq_init(&dq);
            printf("ok\n");
        }else if (!strcmp(command,"debug"))
        {
            printf("front: %i\n",dq.front);
            printf("back: %i\n",dq.back);
            for (int i=0;i<105;i++) //qu_size(&q)
            {
                printf("[%i]",dq.container[i]);
            }
            printf(" .. ");
            //for (int i=NSIZE-11;i<NSIZE-1;i++) //qu_size(&q)
            //{
            //    printf("[%i]",dq.container[i]);
            //}
            printf("\n");
        }
    } while (strcmp(command,"exit"));
    printf("bye\n");
    return 0;
}
*/