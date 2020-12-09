//https://github.com/wwells4/CS433-Project3/blob/master/schedule_rr.c
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#include "task.h"
#include "list.h"
#include "cpu.h"
#include "schedulers.h"

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
 	struct node* temp = head;
 	while (numTasks > 0)
 	{
 		Task *tmp = temp->task;
 		if (tmp->burst > QUANTUM)
 		{
 			run(tmp, QUANTUM);
 			tmp->burst = tmp->burst - QUANTUM;
 			temp = temp->next;
 			if (temp != NULL)
 			{
 				tmp = temp->task;
 			}
 			else
 			{
 				temp = head;
 				if (temp == NULL)
 				{
 					return;
 				}
 				else
 				{
 					tmp = temp->task;
 				}
 			}
 		}
 		else
 		{
 			int time_Remaining = tmp->burst;
 			run(tmp, time_Remaining);
 			tmp->burst = tmp->burst - time_Remaining;
 			temp = temp->next;
 			delete(&head, tmp);
 			if (temp != NULL)
 			{
 				tmp = temp->task;
 			}
 			else
 			{
 				temp = head;
 				if (temp == NULL)
 				{
 					return;
 				}
 				else
 				{
 					tmp = temp->task;
 				}
 			}
 		}
 	}
 }
