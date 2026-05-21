#include <stdio.h>

#include "state.h"
#include "scheduler.h"
#include "events.h"
#include "process_queue.h"

Event* pop_event(EventQueue *event_queue) {
    if (!event_queue || !event_queue->head) return NULL;

    Event *curr_event = event_queue->head;
    event_queue->head = curr_event->next;
    event_queue->size--;
    
    return curr_event;
}

void handle_arrival(SchedulerState *sched_state, Process *proc) {
    enqueue_process(sched_state->process_queue, proc);

    printf("T=%d: Process %s arrived and added to Ready Queue\n", 
            sched_state->current_time, proc->pid); //DEBUG
}

void handle_completion(SchedulerState *sched_state, Process *proc) {
    proc->finish_time = sched_state->current_time;

    sched_state->run_state = false;

    int turnaround_time = proc->finish_time - proc->arrival_time;
    proc->waiting_time = turnaround_time - proc->burst_time;

    printf("T=%d: Process %s completed. (TT: %d, WT: %d)\n",//DEBUG
            sched_state->current_time, proc->pid, turnaround_time, proc->waiting_time);
}

void simulate_scheduler(SchedulerState *state, SchedulingAlgorithm algorithm) {
    printf("Entered simulation");//DEBUG
    ProcessQueue *proc_queue = malloc(sizeof(ProcessQueue));
    proc_queue->head = NULL;
    proc_queue->tail = NULL;
    proc_queue->size = 0;

    state->process_queue = proc_queue;

    EventQueue *event_queue = initialize_events(state);

    while (event_queue->size > 0) {
        printf("Entered primary while loop");//DEBUG
        Event *current = pop_event(event_queue);
        state->current_time = current->time;

        switch (current->type) {
        case EVENT_ARRIVAL:
            handle_arrival(state, current->process);
            break;
        case EVENT_COMPLETION:
            handle_completion(state, current->process);
            break;
        }
        algorithm(state);

        free(current);
    }

    // calculate_metrics(state);
    // print_results(state);
    free(event_queue);
}