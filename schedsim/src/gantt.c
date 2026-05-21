#include <stdio.h>

#include "process.h"
#include "gantt.h"
#include "state.h"

void print_gantt(SchedulerState state) {
    Process *procs = state.processes;
    int n = state.num_processes;

    printf("\nGantt Chart:\n");
    printf("|");
    for (int i = 0; i < n; i++) {
        printf(" %-6s |", procs[i].pid);
    }
    printf("\n");
    printf("%d", procs[0].start_time);
    for (int i = 0; i < n; i++) {
        printf("      %d", procs[i].finish_time);
    }
    printf("\n");
}
