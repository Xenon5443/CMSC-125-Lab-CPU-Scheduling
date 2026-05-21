#include <stdio.h>
#include <limits.h>

#include "process.h"
#include "scheduler.h"
#include "gantt.h"
#include "state.h"

int compare_burst_time(const void *a, const void *b) {
    return (*(Process**)a)->burst_time - (*(Process**)b)->burst_time;
}

int schedule_sjf(SchedulerState *state) {
    Process *ready_queue[state->num_processes];
    int ready_queue_num = 0;
    int n = state->num_processes;

    for (int i = 0; i < n; i++) {
        while (state->current_time < state->processes[i].arrival_time) {
            state->current_time++;
        }

        // To check fo processes that is arrived at the same time
        ready_queue[ready_queue_num++] = &state->processes[i];
        while (i + 1 < n && state->processes[i + 1].arrival_time <= state->current_time) {
            i++;
            ready_queue[ready_queue_num++] = &state->processes[i];
        }

        // Only for SJF, sorts by burst time every process that goes to the ready_queue
        qsort(ready_queue, ready_queue_num, sizeof(Process*), compare_burst_time);

        Process *p = ready_queue[0];
        for (int j = 0; j < ready_queue_num - 1; j++) {
            ready_queue[j] = ready_queue[j + 1];
        }
        ready_queue_num--;

        // Metrics calculations
        p->start_time   = state->current_time;
        p->finish_time  = state->current_time + p->burst_time;
        p->waiting_time = p->start_time - p->arrival_time;

        state->current_time = p->finish_time;

        // Needed to add back processes that arrived while the previous process is running
        while (i + 1 < n && state->processes[i + 1].arrival_time <= state->current_time) {
            i++;
            ready_queue[ready_queue_num++] = &state->processes[i];
        }
    }

    return 0;
}