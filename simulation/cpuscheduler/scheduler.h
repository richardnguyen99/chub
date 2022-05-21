#ifndef __SCHEDULER_H
#define __SCHEDULER_H 1

#include <stdio.h>  // fprintf, stderr, stdout, FILE, fopen
#include <stdlib.h> // exit, EXIT_*
#include <string.h> // strcmp

#define STDOUT(status) (status == 1 ? (stderr) : (stdout))

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

int getalgo(const char *key);
void usage(int status);

#endif // __SCHEDULER_H
