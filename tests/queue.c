#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node
{
        int value;
        struct node *next;
} node;

typedef struct
{
        node *head;
        node *tail;
        int size;
} Queue;

Queue *create_queue();
int size(Queue *queue);
bool is_empty(Queue *queue);
int peek(Queue *queue, bool *status);
void enqueue(Queue *queue, int value);
int dequeue(Queue *queue, bool *status);
void destroy(Queue *queue);



int main(void)
{
        Queue *queue = create_queue();
        if (is_empty(queue)) printf("Queue is empty\n");

        enqueue(queue,5);
        enqueue(queue,6);
        enqueue(queue,7);

        if (!is_empty(queue)) printf("Queue is not empty\n");

        printf("Queue size: %d\n",size(queue));

        bool status = false;
        int value = 0;

        value = peek(queue, &status);

        if(status) printf("peek successful: %d\n",value);

        value = dequeue(queue, &status);

        if (status) printf("dequeue succesful: %d\n",value);
        printf("Queue size: %d\n",size(queue));
               value = peek(queue, &status);

        if(status) printf("peek successful: %d\n",value);

        value = dequeue(queue, &status);

        if (status) printf("dequeue succesful: %d\n",value);
        printf("Queue size: %d\n",size(queue));
               value = peek(queue, &status);

        if(status) printf("peek successful: %d\n",value);

        value = dequeue(queue, &status);

        if (status) printf("dequeue succesful: %d\n",value);
        printf("Queue size: %d\n",size(queue));
               value = peek(queue, &status);

        if(status) printf("peek unsuccessful\n");

        value = dequeue(queue, &status);

        if (!status) printf("dequeue unsuccesful\n");
        printf("Queue size: %d\n",size(queue));

        return 0;
}
Queue *create_queue()
{
        Queue *queue = malloc(sizeof(Queue));

        queue->head = NULL;
        queue->tail = NULL;
        queue->size = 0;

        return queue;
}
int size(Queue *queue)
{
        return queue->size;
}
bool is_empty(Queue *queue)
{
        return queue->size == 0;
}
int peek(Queue *queue, bool *status)
{
        if (is_empty(queue))
        {
                *status = false;
                return NULL;
        }

        *status = true;
        return queue->head->value;
}
void enqueue(Queue *queue, int value)
{
        node *newnode = malloc(sizeof(node));
        newnode->value = value;
        newnode->next = NULL;

        if (is_empty(queue))
        {
                queue->head = newnode;
                queue->tail = newnode;;
        }
        else
        {        
                queue->tail->next = newnode;
                queue->tail = newnode;
        }

        queue->size++;
}
int dequeue(Queue *queue, bool *status)
{
        if (is_empty(queue))
        {
                *status = false;
                return NULL;
        }

        *status = true;
        int value = queue->head->value;
        node *oldhead = queue->head;

        if (queue->size == 1)
        {
                queue->head = NULL;
                queue->tail = NULL;
        }
        else
                queue->head = queue->head->next;

        free(oldhead);

        queue->size--;
        return value;
}
void destroy(Queue *queue)
{
        node *currentnode = queue->head;
        while (currentnode != NULL)
        {
                node *nextnode = currentnode;
                currentnode = currentnode->next;
                free(nextnode);

        }
        free(queue);
}