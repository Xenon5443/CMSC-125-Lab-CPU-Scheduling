#ifndef PROCESS_QUEUE_H
#define PROCESS_QUEUE_H

#include <stdlib.h>

#include "process.h"
#include "state.h"

typedef struct ProcessNode {
    Process *process;
    struct ProcessNode *next;
} ProcessNode;

typedef struct ProcessQueue {
    ProcessNode *head;
    ProcessNode *tail;
    int size;
} ProcessQueue;

void enqueue_process(ProcessQueue *process_queue, Process *event);
Process* dequeue_process(ProcessQueue *process_queue);

#endif