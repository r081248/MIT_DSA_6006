#include<stdio.h>
#include<stdlib.h>

typedef struct{
unsigned int size;
int *list;
int top;
}stack;

void initialize_stack(stack *stack,unsigned int size)
{
    stack->size = size;
    stack->list = (int *)malloc(sizeof(int)*size);
    stack->top = -1;
    return;
}

int is_stack_overflown(stack *stack)
{
    if(stack->size == (stack->top+1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int is_stack_underflown(stack *stack)
{
    if(stack->top == -1)
    {
        return 1;
    }
    return 0;
}

int push(stack *stack, int value)
{
    if(!is_stack_overflown(stack))
    {
        stack->list[++(stack->top)] = value;
        return 1;        
    }
    return 0;    
}

int pop(stack *stack, int *value)
{
    if(!is_stack_underflown(stack))
    {
        *value = stack->list[(stack->top)--];
        return 1;
    }
    return 0;    
}


int main()
{
    stack stack;
    initialize_stack(&stack, 10);
    for(int i=0;push(&stack,i);++i);
    int value;
    while(pop(&stack, &value))
    {
        printf("%d ",value);
    }
    printf("\n");
    return 0;   
}
