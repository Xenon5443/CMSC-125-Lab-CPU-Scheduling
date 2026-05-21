#include <stdio.h>
#include <limits.h>

#include "scheduler.h"
#include "state.h"

int schedule_fcfs(SchedulerState *state) {
    for (int i = 0; i < state->num_processes; i++) {
        if (state->current_time < state->processes[i].arrival_time){
            state->current_time++;
        }

        //Metrics calculations
        state->processes[i].start_time  = state->current_time;
        state->processes[i].finish_time = state->current_time + state->processes[i].burst_time;
        state->processes[i].waiting_time = state->processes[i].start_time - state->processes[i].arrival_time;

        state->current_time = state->processes[i].finish_time;
    }

    return 0;
}