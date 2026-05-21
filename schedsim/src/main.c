#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "process.h"
#include "parse.h"
#include "state.h"
#include "metrics.h"
#include "scheduler.h"

int main (int argc, char* args[]){
    InputArgs* args_info;
    args_info = parse_args(argc, args);
    if (args_info -> process == NULL) {
        perror("Missing Process input");
        return 1;
    }

    //Initialize sched state, its going to be used in all parts
    SchedulerState* sched_state = (SchedulerState*) malloc(sizeof(SchedulerState));
    memset(sched_state, 0, sizeof(SchedulerState));

    //Populate the sched_state
    sched_state -> processes = get_process(args_info -> process);
    sched_state -> num_processes = count_processes(args_info -> process);


    print_scheduler_state(sched_state);//DEBUG   
    
    SchedulingAlgorithm algorithm;

    //Find where to send the process info 
    if (!strcmp(args_info -> algorithm, "FCFS")) {
        algorithm = schedule_fcfs;

    } else if (!strcmp(args_info -> algorithm, "RR")) {
        algorithm = schedule_rr;

    } else if (!strcmp(args_info -> algorithm, "SJF")) {
        algorithm = schedule_sjf;

    } else if (!strcmp(args_info -> algorithm, "STCF")) {
        algorithm = schedule_stcf;
    } else{
        perror("Missing algorithm value");
    }

    simulate_scheduler(sched_state, algorithm);
    free(args_info);
}

