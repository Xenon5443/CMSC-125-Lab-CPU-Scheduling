#include <stdio.h>
#include <stdlib.h>

#include "events.h"

void enqueue_event(EventQueue* event_queue, Event* event) {
    if (!event_queue) return;

    if (event_queue->head == NULL) {
        //For head
        event_queue->head = event;     
        event->next = NULL; 
    } else {
        Event* curr = event_queue->head;
        Event* prev = NULL;

        //Sort by arrival through insertion
        while (curr != NULL && event->time >= curr->time) {
            prev = curr;
            curr = curr->next;
        }
        
        event->next = curr;

        if (prev == NULL) {
            //For head
            event_queue->head = event;
        } else {
            prev->next = event;
        }
    } 
    event_queue->size++;
}

EventQueue* initialize_events(SchedulerState *state) {
    //Make event_queue to store all process events
    EventQueue *event_queue = malloc(sizeof(EventQueue));
    if (!event_queue) return NULL;
    
    event_queue->head = NULL;
    event_queue->size = 0;

    //Populate events sorted by time to initialize e_queue properly
    for (int i = 0; i < state->num_processes; i++) {
        Event *event = malloc(sizeof(Event));
        event->time = state->processes[i].arrival_time;
        event->type = EVENT_ARRIVAL;
        event->process = &state->processes[i];
        event->next= NULL;

        enqueue_event(event_queue, event);
    }

    return event_queue;
}