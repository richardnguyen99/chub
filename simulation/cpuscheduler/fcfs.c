#include "fcfs.h"

int fcfs(FILE *ready_queue, int mode)
{
    char *linebuf = NULL;
    size_t bufsize = 0;
    char *tokens[2];
    ssize_t nread;

    while ((nread = getline(&linebuf, &bufsize, ready_queue)) >= 0)
    {
        int i = 0;

        linebuf[nread - 1] = '\0';
        char *p = strtok(linebuf, " ");

        while (p != NULL && i < 2)
        {
            tokens[i++] = p;
            p = strtok(NULL, " ");
        }

        printf("%c", tokens[1][0]);
        // printf("%ld", nread);
        if (tokens[1][nread - 1] == '\n')
        {
            tokens[1][nread - 1] = '\0';
        }

        fprintf(stdout, "Proccess %s has runtime: %s steps\n", tokens[0], tokens[1]);
    }

    free(linebuf);
    linebuf = NULL;

    return 0;
}
