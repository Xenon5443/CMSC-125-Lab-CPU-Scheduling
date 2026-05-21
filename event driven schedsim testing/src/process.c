#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "process.h"

int count_processes(char* process_str){
    int num_proc = 1;
    for (int i = 0; process_str[i]; i++) {
        if (process_str[i] == ','){
             num_proc++;
        }
    }

    return num_proc;
}

Process* get_process(char* process_strings) {
    char* process_cpy = strdup(process_strings);
    char* process_cpy_ptr = process_cpy;
    
    int num_proc = count_processes(process_strings);

    Process* process_array = (Process*) malloc(num_proc * sizeof(Process));
    if (!process_array) {
        free(process_cpy);
        return NULL;
    }

    char* token;
    int i = 0;
    int arg_count;
    char *saveptr;
    // Format for process string is pid:arrival:burst
    // The first call uses process_cpy_ptr
    token = strtok_r(process_cpy_ptr, ",", &saveptr);

    while (token != NULL) {
        arg_count = sscanf(token, "%15[^:]:%d:%d", 
                process_array[i].pid, 
                &process_array[i].arrival_time, 
                &process_array[i].burst_time
            );

        if (arg_count != 3) {
            perror("Invalid process arguments");
        }

        process_array[i].remaining_time = process_array[i].burst_time; 
        process_array[i].time_in_queue = 0;
        process_array[i].waiting_time = 0;   
        process_array[i].remaining_time = process_array[i].burst_time;
        process_array[i].start_time = -1;  
        process_array[i].finish_time = -1; 
        
        i++;
        token = strtok_r(NULL, ",", &saveptr);
    }

        free(process_cpy);
        return process_array;
    }