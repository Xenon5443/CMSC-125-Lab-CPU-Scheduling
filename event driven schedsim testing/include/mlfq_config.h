#ifndef MLFQConfig_H
#define MLFQConfig_H

#include "process.h"

typedef struct {
    //Placeholders
    Process *processes;
    int num_processes;
    int current_time;
} MLFQConfig;

#endif