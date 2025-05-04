#include <stdio.h>
#include <stdlib.h>
#include "func.h"

void init_stack(stack_arr *st)
{
    st->size = 4;
    st->sp = 0;
    st->item = malloc(st->size * sizeof(datatype));
}

void delete_stack(stack_arr *st)
{
    free(st->item);
}

void push_arr(stack_arr *st, datatype value)
{
    if (st->sp >= st->size - 1)
    {
        st->size *= 2;
        st->item = realloc(st->item, st->size * sizeof(datatype));
    }
    st->item[st->sp++] = value;
}

int empty_stack_arr(stack_arr *st)
{
    return (st->sp < 1);
}
void pop_arr(stack_arr *st, datatype *value)
{
    if (st->sp < 1)
    {
        printf("stack empty");
        exit(1);
    }
    *value = st->item[--(st->sp)];
}

void push(stack **p, datatype data)
{
    stack *ptmp;
    ptmp = malloc(sizeof(stack));
    ptmp->value = data;
    ptmp->next = *p;
    *p = ptmp;
}

_Bool empty_stack(stack *p)
{
    return p == NULL; // вернет 1
}

datatype pop(stack **p)
{
    stack *ptmp = *p;
    datatype c;
    if (empty_stack(*p))
        exit(1); // Попытка взять из пустого стека
    c = ptmp->value;
    *p = ptmp->next;
    free(ptmp);
    return c;
}

_Bool empty_queue(queue *p)
{
    return p == NULL;
}

void enqueue(queue **pl, datatype data)
{
    queue *ptmp = *pl;
    queue *elem = malloc(sizeof(queue));
    elem->value = data;
    elem->next = NULL;
    if (empty_queue(*pl))
    {
        *pl = elem;
        return;
    }
    while (ptmp->next)
        ptmp = ptmp->next;
    ptmp->next = elem;
}

datatype dequeue(queue **p)
{
    queue *ptmp = *p;
    datatype c;
    if (empty_queue(*p))
    { // Попытка взять из пустой очереди
        fprintf(stderr, "Error. Queue is empty\n");
        exit(1);
    }
    c = ptmp->value;
    *p = ptmp->next;
    free(ptmp);
    return c;
}

void enqueue_recurs(queue **pl, datatype data)
{
    if (*pl == NULL)
    {
        (*pl) = malloc(sizeof(struct list));
        (*pl)->value = data;
        (*pl)->next = NULL;
        return;
    }
    else
    {
        enqueue_recurs(&((*pl)->next), data);
    }
}

int main(void)
{
    stack *p = NULL; // Важно для корректной работы присвоить NULL

    D printf("This is debug message\n");
    for (int i = 1; i <= 5; i++)
        push(&p, i);
    printf("Stack: \n");
    for (int i = 1; i <= 5; i++)
        printf("%d, ", pop(&p));

    stack_arr st;
    stack_arr *pst = &st;
    init_stack(pst);
    for (int i = 1; i <= 5; i++)
        push_arr(pst, i);
    datatype value;
    printf("\nStack array: \n");
    for (int i = 1; i <= 5; i++)
    {
        pop_arr(pst, &value);
        printf("%d, ", value);
    }
    delete_stack(pst);

    printf("\nQueue: \n");
    queue *pq = NULL;
    for (int i = 1; i <= 5; i++)
        enqueue_recurs(&pq, i);
    for (int i = 1; i <= 5; i++)
        printf("%d, ", dequeue(&pq));
    fprintf(stderr,"Debug message\n");
    fprintf(stdout,"Stdout message\n");
    return 0;
}
