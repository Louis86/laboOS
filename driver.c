/**
 * Driver.c
 *
 * Schedule is in the format
 *
 *  [name] [priority] [CPU burst]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task.h"
#include "list.h"
#include "schedulers.h"

#define SIZE    100

int main(int argc, char *argv[])
{
    FILE *in;
    char *temp;
    char task[SIZE];

    char *name;
    int priority;
    int burst;
    struct node *nhead = NULL;
    struct node *test=NULL;
    in = fopen(argv[1],"r");

    while (fgets(task,SIZE,in) != NULL) {
        temp = strdup(task);
        name = strsep(&temp,",");
        priority = atoi(strsep(&temp,","));
        burst = atoi(strsep(&temp,","));


        // add the task to the scheduler's list of tasks
        add(name,priority,burst, &nhead);

        //printf("[%s] [%d] [%d]\n",nhead->task->name, nhead->task->priority, nhead->task->burst);

        free(temp);
    }
    //poplast(&nhead,&test);
    //printf("[%s]",test->task->name);
    //traverse(nhead);
    fclose(in);

    // invoke the scheduler
    schedule(nhead);

    return 0;
}
