#ifndef __SCHEDULER_DEFS
#define __SCHEDULER_DEFS 1

#include <stdio.h>  // fprintf, stderr, stdout, FILE, fopen, getline
#include <stdlib.h> // exit, EXIT_*, size_t
#include <string.h> // str*

#define STDOUT(status) (status == 1 ? (stderr) : (stdout))

#define SCHED_OUT 0x1
#define SCHED_WAIT 0x2
#define SCHED_RESP 0x4
#define SCHED_FULL 0x7

#endif // __SCHEDULER_DEFS
