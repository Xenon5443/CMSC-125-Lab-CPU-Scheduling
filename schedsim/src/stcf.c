#include <stdio.h>
#include <limits.h>
#include "../include/process.h"

#include "../include/scheduler.h"
#include "../include/gantt.h"

int schedule_stcf(SchedulerState *state){
    Process *p = state->processes;
    int n = state->num_processes;
    int completed = 0;
    int time = 0;

    while (completed < n) {
        int shortest = -1;
        int min_remaining = INT_MAX;

        /* Find process with shortest remaining time */
        for (int i = 0; i < n; i++) {

            if (p[i].arrival_time <= time &&
                p[i].remaining_time > 0 &&
                p[i].remaining_time < min_remaining) {

                min_remaining = p[i].remaining_time;
                shortest = i;
            }
        }

        /* If no process ready */
        if (shortest == -1) {
            gantt_record(time, "-");
            time++;
            continue;
        }

        Process *proc = &p[shortest];

        /* Record first execution time */
        if (proc->start_time == -1) {
            proc->start_time = time;
        }

        /* Execute for 1 time unit */
        gantt_record(time, proc->pid);

        proc->remaining_time--;
        time++;

        /* Check completion */
        if (proc->remaining_time == 0) {
            proc->finish_time = time;
            completed++;
        }
    }

    state->current_time = time;

    return 0;
}