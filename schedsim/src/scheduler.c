#include <stdio.h>

#include "state.h"
#include "scheduler.h"
#include "gantt.h"
#include "metrics.h"

int compare_arrival_time(const void *a, const void *b) {
    return ((Process*)a)->arrival_time - ((Process*)b)->arrival_time;
}

void simulate_scheduler(SchedulerState *state, SchedulingAlgorithm algorithm) {
    //Initialize time
    state -> current_time = 0;

    //sort arrival time to simulate event queue
    qsort(state->processes, state->num_processes, sizeof(Process), compare_arrival_time);
    
    algorithm(state);

    print_scheduler_state(state);
    print_gantt(*state);
}