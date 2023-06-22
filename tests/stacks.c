#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
        int *collections;
        int capacity;
        int size;

} stack;

stack *create_stack(int capacity);
void destroy_stack(stack *stack);
bool is_empty(stack *stack);
bool is_full(stack *stack);
bool pop(stack *stack, int *item);
bool push(stack *stack, int item);
bool peek(stack *stack, int *item);

int main(void)
{
        stack *stack = create_stack(5);

        if (stack == NULL)
        {
                printf("error creating stack\n");
                return 1;
        }

        if (is_empty(stack)) printf("empty stack\n");
        push(stack, 10);
        push(stack, 2);
        push(stack, 3);
        push(stack, 5);
        push(stack, 100);

        if (is_full(stack)) printf("stack is full\n");

        int peek_val = 0;
        peek(stack, &peek_val);
        printf("peek_val = %d\n", peek_val);
        // bool try_push = push(stack, 23);
        // if (try_push == false) printf("push failed\n");
        // printf("stacksize: %d\n", stack->size);


        int pop_val = 0;
        for (int i = 0; i < stack->size;i++)
        {
                pop(stack, &pop_val);
                printf("poped: %d\n", pop_val);
        }
        destroy_stack(stack);
        return (0);
}

stack *create_stack(int capacity)
{
        if (capacity <= 0) return NULL;

        stack *stack = malloc(sizeof(stack));
        if (stack == NULL) return NULL;

        stack->collections = malloc(capacity * sizeof(int));

        if (stack->collections == NULL) 
        {
                free(stack);
                return NULL;
        }

        stack->capacity = capacity;
        stack->size = 0;

        return stack;
}

void destroy_stack(stack *stack)
{
        free(stack->collections);
        free(stack);
}

bool is_full(stack *stack)
{
        return stack->capacity == stack->size;
}

bool is_empty(stack *stack)
{
        return stack->size == 0;
}

bool push(stack *stack, int item)
{
        if (is_full(stack)) return false;
        stack->collections[stack->size] = item;
        stack->size++;

        return true;
}
bool peek(stack *stack, int *item)
{
        if (is_empty(stack)) return false;
        *item = stack->collections[stack->size - 1];
        return true;
}
bool pop(stack *stack, int *item)
{
        if (is_empty(stack)) return false;

        stack->size--;

        *item = stack->collections[stack->size];
        return true;

}