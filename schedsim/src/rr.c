#include <stdio.h>
#include <stdlib.h>
#include "../include/process.h"

#include "../include/scheduler.h"
#include "../include/gantt.h"

#define MAX_QUEUE 1000

int schedule_rr(SchedulerState *state, int quantum){
    Process *p = state->processes;
    int n = state->num_processes;

    int queue[MAX_QUEUE];
    int front = 0, rear = 0;

    int completed = 0;
    int time = 0;

    while (completed < n) {
        /* Add arriving processes */
        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time == time) {
                queue[rear++] = i;
            }
        }

        /* If no process ready, advance time */
        if (front == rear) {
            time++;
            continue;
        }

        int idx = queue[front++];
        Process *proc = &p[idx];

        /* First time execution → response time */
        if (proc->start_time == -1) {
            proc->start_time = time;
        }

        int run_time =
            (proc->remaining_time < quantum)
                ? proc->remaining_time
                : quantum;

        /* Execute process */
        for (int t = 0; t < run_time; t++) {
            gantt_record(time, proc->pid);
            time++;

            /* Check for newly arriving processes */
            for (int j = 0; j < n; j++) {
                if (p[j].arrival_time == time) {
                    queue[rear++] = j;
                }
            }
        }

        proc->remaining_time -= run_time;

        /* Process finished */
        if (proc->remaining_time == 0) {
            proc->finish_time = time;
            completed++;
        }
        else {
            queue[rear++] = idx;
        }
    }

    state->current_time = time;
    return 0;
}