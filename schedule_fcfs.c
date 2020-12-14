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
  int time = 0;
  int j = 0;
	while(numTasks > 0)
	{
		Task *tmp = head->task;
    time =+ tmp->burst;
		run(tmp, tmp->burst);
		delete(&head, tmp);
		numTasks--;
    j++;
	}
float waiting= (float)time/(float)(j+1);
//time+=task->burst;
//free(head->task->name);
//free(head->task);
//free(head);
float turn= (float)time/(float)(j+1);
printf("%f Average waiting time \n", waiting);
//printf("%f Average turnaround time \n", turn);
}
