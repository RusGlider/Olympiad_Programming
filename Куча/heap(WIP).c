#include <stdio.h>
#include <stdlib.h>
#define MAXN 10050

typedef struct
{
    int size;
    int container[MAXN];
}Heap;

int heap_getmin(Heap *h)
{
    return h->container[0];
}

void heap_add(Heap *h, int n)
{
    int y, pos = h->size, parent;
    h->container[h->size++] = n;
    parent = (pos-1)/2;
    while (pos && h->container[pos] > h->container[parent])
    {
        y = h->container[parent];
        h->container[parent] = h->container[pos];
        h->container[pos] = y;
        pos = parent;
        parent = (pos-1)/2;
    }
}

void heap_del(Heap *h)
{
    int min_child, y, pos = 0;
    h->container[0] = h->container[--h->size];
    while (pos*2+1 < h->size)
    {
        y = pos*2+1;
        min_child = h->container[y] > h->container[y+1] ? y : y+1;
        if (h->container[pos] < h->container[min_child])
        {
            y = h->container[pos];
            h->container[pos] = h->container[min_child];
            h->container[min_child] = y;
            pos = min_child;
        }else
        {
            break;
        }
    }
}

int heap_shiftup(Heap *h,int i)
{
    int y, pos = i, parent;
    parent = (pos-1)/2;
    while (pos && h->container[pos] > h->container[parent])
    {
        y = h->container[parent];
        h->container[parent] = h->container[pos];
        h->container[pos] = y;
        pos = parent;
        parent = (pos-1)/2;
        if (parent < 0) break;
    }
    return pos;
}


int heap_shiftdown(Heap *h,int i)
{
    int y, pos = i, max_child;
    //parent = (pos-1)/2;
    while (pos*2+1 < h->size)
    {
        y = pos*2+1;
        max_child = h->container[y] > h->container[y+1] ? y : y+1;
        if (h->container[pos] < h->container[max_child])
        {
            y = h->container[pos];
            h->container[pos] = h->container[max_child];
            h->container[max_child] = y;
            pos = max_child;
        }else
        {
            break;
        }
    }
    return pos;
}


int main (void)
{
    Heap h = {.size = 0};
    int n,m,i,x;
    scanf("%i",&n);
    for (int j=0;j<n;j++)
    {
        int input;
        scanf("%i",&input);
        heap_add(&h,input);
    }
    scanf("%i",&m);
    for (int j=0;j<m;j++)
    {
        scanf("%i %i",&i,&x);
        h.container[i-1] += x;
        printf("%i\n",heap_shiftup(&h, i-1)+1);

        //h.container[i-1] -= x;
        //printf("%i\n",heap_shiftdown(&h, i-1)+1);
    }



    for (int j=0;j<h.size;j++)
    {
        printf("%i ",h.container[j]);
    }
}