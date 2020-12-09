#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "schedulers.h"
#include "cpu.h"

struct node *head;
int numTasks = 0;

void add(char *name, int priority, int burst)
{
	Task *tmp = malloc(sizeof(struct node));
	tmp->name = name;
	tmp->priority = priority;
	tmp->burst = burst;
	insert(&head, tmp);
	numTasks++;
}

void schedule()
{
	//FCFS

	while(numTasks > 0)
	{
		Task *tmp = head->task;
		run(tmp, tmp->burst);
		delete(&head, tmp);
		numTasks--;
	}
}
