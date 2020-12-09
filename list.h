/**
 * list data structure containing the tasks in the system
 */
#ifndef NODE_H
#define NODE_H
#include "task.h"

struct node {
    Task *task;
    struct node *next;
};

// insert and delete operations.
void insert(struct node **head, Task *task);
void delete(struct node **head, Task *task);
void traverse(struct node *head);
struct node *getByPriority(struct node *head);
int poplast(struct node **head, struct node **topop);


#endif
