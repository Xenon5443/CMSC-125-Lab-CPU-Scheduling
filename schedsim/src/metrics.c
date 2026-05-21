#include <stdio.h>
#include "process.h"
#include "state.h"

#include <stdio.h>
#include "process.h"
#include "state.h"

void print_scheduler_state(SchedulerState *state) {
    printf("\n--- Scheduler State (Current Time: %d) ---\n", state->current_time);
    
    printf("%-8s %-4s %-4s %-4s %-6s %-4s %-4s %-4s %-6s\n", 
           "PID", "Arr", "Bst", "Rem", "Start", "Fin", "Wait", "Prio", "QTime");
    printf("--------------------------------------------------------------------\n");

    for (int i = 0; i < state->num_processes; i++) {
        Process *p = &state->processes[i];

        printf("%-8s %-4d %-4d %-4d %-6d %-4d %-4d %-4d %-6d\n",
               p->pid,
               p->arrival_time,
               p->burst_time,
               p->remaining_time,
               p->start_time,
               p->finish_time,
               p->waiting_time,
               p->priority,
               p->time_in_queue);
    }
    printf("--------------------------------------------------------------------\n\n");
}
