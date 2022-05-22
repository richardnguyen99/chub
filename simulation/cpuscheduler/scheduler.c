#include <getopt.h> // option, getopt_long
#include <errno.h>  // errno, strerror

#include "scheduler.h"
#include "fcfs.h"

int get_scheduler(const char *key)
{
    static scheduler_t lookup[] =
        {
            {"FCFS", FCFS},
            {"ROBIN", ROBIN},
            {"SJF", SJF},
            {"SMTF", SMTF},
            {"PRIOR", PRIOR},
            {"MULTI", MULTI},
            {"FDBACK", FDBACK},
        };

    int lookupsize = sizeof(lookup) / sizeof(lookup[0]);

    for (int i = 0; i < lookupsize; i++)
    {
        scheduler_t sched = lookup[i];
        if (strcmp(key, sched.key) == 0)
            return sched.code;
    }

    return -1;
}

void usage(int status)
{
    FILE *out = STDOUT(status);

    fprintf(out, "\
Usage: scheduler [POLICY] [OPTIONS] [FILES]... \n\
\n\
CPU-scheduling simulator.\n\
\n\
-p, --policy            Specify a scheduling policy\n\
                            FCFS (First-come First-serve)\n\
                            ROBIN (Round Robin)\n\
                            SJF (Shortest-job first)\n\
                            SMTF (Shortest-remaining-time first)\n\
                            PRIOR (Priority Queue)\n\
                            MULTI (Multilevel Queue)\n\
                            FDBACK (Multilevel-Feedback Queue)\n\
\n\
-f, --full              Fully report\n\
-w, --waiting           Display average waiting time\n\
-r, --response          Display average response time\n\
    ");
}

int simulate(int policy, FILE *ready_queue, int mode)
{
    if ((mode & SCHED_OUT) == 0x0)
    {
        fprintf(stderr, "simulate() requires to have SCHED_OUT to display\n");
        exit(EXIT_FAILURE);
    }

    if (policy == FCFS)
        return fcfs(ready_queue, mode);

    return -1;
}

int main(int argc, char **argv)
{
    static const char *filename = "-";

    int algo = -1;
    // int full = 0;
    int waiting = 0;
    int response = 0;

    static struct option const longopt[] =
        {
            {"policy", required_argument, NULL, 'p'},
            {"full", no_argument, NULL, 'f'},
            {"waiting", no_argument, NULL, 'w'},
            {"response", no_argument, NULL, 'r'},
        };
    const char *shortopt = "p:fwr";

    int c;
    while ((c = getopt_long(argc, argv, shortopt, longopt, NULL)) != -1)
    {
        switch (c)
        {
        case 'p':
            algo = get_scheduler(optarg);

            if (algo == -1)
            {
                fprintf(stderr, "scheduler: unknown %s policy\n", optarg);
                usage(1);
                exit(EXIT_FAILURE);
            }

            break;
        case 'f':
            // full = 1;
            waiting = 1;
            response = 1;
            break;
        case 'w':
            waiting = 1;
            break;
        case 'r':
            response = 1;
            break;
        default:
            usage(1);
            exit(EXIT_FAILURE);
        }
    }

    int argind = optind;

    if (argind < argc - 1)
    {
        fprintf(stderr, "Scheduler only accepts one file. Too many file after \"%s\"\n", argv[argind]);
        exit(EXIT_FAILURE);
    }

    if (algo == -1)
    {
        fprintf(stderr, "Scheduler requires a scheduling policy. See option '-p'\n");
        exit(EXIT_FAILURE);
    }

    if (argind < argc)
        filename = argv[argind];

    if (strcmp(filename, "-") == 0)
    {
        fprintf(stderr, "scheduler: Test file is missing\n");
        exit(EXIT_FAILURE);
    }

    FILE *file;

    if ((file = fopen(argv[argind], "r")) == NULL)
    {
        fprintf(stderr, "scheduler: unable to open file %s\n", argv[argind]);
        exit(EXIT_FAILURE);
    }

    int mode = SCHED_OUT;

    if (waiting)
        mode |= SCHED_WAIT;
    if (response)
        mode |= SCHED_RESP;

    simulate(algo, file, mode);

    return 0;
}
