#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "schedulers.h"
#include "cpu.h"

int pid =0;
void add(char *name, int priority, int burst, struct node **head)
{
Task *newtask = malloc(sizeof(Task));
if(newtask==NULL)
{
  printf("bad \n" );
}
newtask->tid=pid;
pid++;
newtask->priority=priority;
newtask->burst=burst;
newtask->name=(char*)malloc(sizeof(char)*24);
if(newtask->name==NULL)
{
  printf("bad \n");
}
strcpy(newtask->name, name);
insert(head, newtask);
//printf("[%s] [%d] [%d]\n",head->task->name, head->task->priority, head->task->burst);

traverse(*head);
printf("bad \n");
}


void schedule(struct node *head)
{
  int time=0;
  int i;
  int j=0;
  struct node *temp=NULL;
  i=poplast(&head, &temp);
  while(i==0)
  {
    printf("ok");
    run(temp->task,1);
    time+=temp->task->burst;
    free(temp->task->name);
    free(temp->task);
    free(temp);
    i=poplast(&head, &temp);
    j++;
  }
  run(head->task, 1);
  float waiting= (float)time/(float)(j+1);
  time+=head->task->burst;
  free(head->task->name);
  free(head->task);
  free(head);
  float turn= (float)time/(float)(j+1);
  printf("%f Average waiting time \n", waiting);
  printf("%f Average turnaround time \n", turn);

}
