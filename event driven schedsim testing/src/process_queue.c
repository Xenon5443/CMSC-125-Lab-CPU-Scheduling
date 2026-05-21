#include <stdlib.h>
#include "process_queue.h"

void enqueue_process(ProcessQueue *proc_queue, Process *proc) {
    if (!proc_queue || !proc) return;

    ProcessNode *new_node = malloc(sizeof(ProcessNode));
    new_node->process = proc;
    new_node->next = NULL;

    if (proc_queue->head == NULL) {
        proc_queue->head = new_node;
        proc_queue->tail = new_node;
    } else {
        proc_queue->tail->next = new_node;
        proc_queue->tail = new_node;
    }
    
    proc_queue->size++;
}

Process* dequeue_process(ProcessQueue *proc_queue) {
    if (!proc_queue || !proc_queue->head) return NULL;

    ProcessNode *curr_proc = proc_queue->head;
    Process *p = curr_proc->process;

    proc_queue->head = proc_queue->head->next;
    if (proc_queue->head == NULL) {
        proc_queue->tail = NULL;
    }

    free(curr_proc);
    proc_queue->size--;
    return p;
}