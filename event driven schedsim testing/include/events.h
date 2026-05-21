#ifndef EVENTS_H
#define EVENTS_H

#include <stdlib.h>

#include "process.h"
#include "state.h"

typedef enum {
    EVENT_ARRIVAL,
    EVENT_COMPLETION,
    EVENT_QUANTUM_EXPIRE,
    EVENT_PRIORITY_BOOST
} EventType;

typedef struct Event {
    int time;
    EventType type;
    Process *process;
    struct Event *next;
} Event;

typedef struct EventQueue {
    Event *head;
    int size;
} EventQueue;

void enqueue_event(EventQueue *event_queue, Event *event);
EventQueue *initialize_events(SchedulerState *state);

#endif