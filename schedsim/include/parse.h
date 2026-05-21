#ifndef PARSE_H
#define PARSE_H

#include <stdbool.h>

#include "process.h"

typedef struct {
    char* algorithm;
    char* process;
    bool compare;
    char* input;
    char* mlfq_config;
    int quantum;
} InputArgs;

InputArgs* parse_args(int argc, char* args[]);

#endif