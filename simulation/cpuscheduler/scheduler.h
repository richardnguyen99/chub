#ifndef __SCHEDULER_H
#define __SCHEDULER_H 1

#include "def.h"
typedef struct
{
    char *key;
    int code;
} scheduler_t;

enum SCHED_CODE
{
    FCFS,
    ROBIN,
    SJF,
    SMTF,
    PRIOR,
    MULTI,
    FDBACK,
};

typedef struct
{
    int pid;
    int burst;
    int prio;
} process_t;

int get_scheduler(const char *key);
int simulate(int policy, FILE *ready_queue, int mode);
void usage(int status);

#endif // __SCHEDULER_H
