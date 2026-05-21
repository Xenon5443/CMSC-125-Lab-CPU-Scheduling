#ifndef STATE_H
#define STATE_H

#include <stdbool.h>

#include "events.h"
#include "process.h"
#include "mlfq_config.h"

typedef struct ProcessQueue ProcessQueue;

typedef struct {
    Process *processes;
    int num_processes;
    int current_time;

    EventQueue *event_queue;
    ProcessQueue *process_queue;
    bool run_state;
} SchedulerState;

int schedule_fcfs(SchedulerState *state);
int schedule_sjf(SchedulerState *state);
int schedule_stcf(SchedulerState *state);
int schedule_rr(SchedulerState *state, int quantum);
int schedule_mlfq(SchedulerState *state, MLFQConfig *config);

#endif