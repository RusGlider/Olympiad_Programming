#include <stdio.h>
#include <string.h>

typedef struct stack
{
    int container[100];
    int len; // индекс последнего элемента

}stack;


void stack_push(stack *stk,int n)
{
    stk->len++;
    stk->container[stk->len] = n;
    printf("ok\n");
}

void stack_pop(stack *stk)
{
    if (stk->len >=0)
    {
        stk->len--;
        printf("%i\n",stk->container[(stk->len)+1]);
        //return stk->container[(stk->len)+1];
    }else
    {
        printf("error\n");
    }
}

void stack_back(stack *stk)
{
    if (stk->len >=0)
    {
        printf("%i\n",stk->container[stk->len]);
        //return stk->container[(stk->len)+1];
    }else
    {
        printf("error\n");
    }

    //return stk->container[stk->len];
}

void stack_clear(stack *stk)
{
    stk->len = -1;
    printf("ok\n");
}


int stack_size(stack *stk)
{
    return stk->len+1;
}

int main(void)
{
    stack stk = {.len=-1};
    char command[5];
    do
    {
        scanf("%s",command);
        if (!strcmp(command,"push"))
        {
            int n;
            scanf("%i",&n);
            stack_push(&stk,n);
        }else if (!strcmp(command,"pop"))
        {
            stack_pop(&stk);
            //printf("%i\n",stack_pop(&stk));
        }else if (!strcmp(command,"back"))
        {
            stack_back(&stk);
            //printf("%i\n",stack_back(&stk));
        }else if (!strcmp(command,"size"))
        {
            printf("%i\n",stack_size(&stk));
        }else if (!strcmp(command,"clear"))
        {
            stack_clear(&stk);
        }
    } while (strcmp(command,"exit"));
    printf("bye\n");
    return 0;
}