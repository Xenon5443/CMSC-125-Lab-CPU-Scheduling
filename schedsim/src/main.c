#include <stdio.h>

#include "process.h"

int main (int argc, char* args[]){

    //Just call error if missing args
    if (argc < 3){
        perror("Incorrect nymber of arguments");
        return 1;
    }

    //static int global_time = 0; might be inside the algorithms instead

    //get the metrics part of the info

    //Find where to send the process info
    char* algorithm_info = strdup(args[1]);
    algorithm_info = strtok(algorithm_info,"=");

    char* algotrithm_name = strtok(NULL, "=");

    if (!strcmp(algotrithm_name, "FCFS")) {
        //do FCFS func

    } else if (!strcmp(algotrithm_name, "RR")) {
        //else do round robin func

    } else if (!strcmp(algotrithm_name, "SJF")) {
        //sjf

    } else if (!strcmp(algotrithm_name, "STCF")) {
        //stcf
    }

    free(algorithm_info);
}