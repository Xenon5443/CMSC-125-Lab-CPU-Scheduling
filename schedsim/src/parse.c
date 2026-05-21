#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

#include "parse.h"

struct option long_opts[] = {
    {"algorithm", required_argument, NULL, 'a'},
    {"processes", required_argument, NULL, 'p'},
    {"compare", no_argument, NULL, 'c'},
    {"input", required_argument, NULL, 'i'},
    {"quantum", required_argument, NULL, 'q'},
    {"mlfq_config", required_argument, NULL, 'm'},
    {NULL}
};

InputArgs* parse_args(int argc, char* args[]){
    InputArgs* args_info = (InputArgs*) malloc(sizeof(InputArgs));
    memset(args_info, 0, sizeof(InputArgs));
    
    int opt;
    while ((opt = getopt_long(argc, args, "a:p:c:i:q:m:", long_opts, NULL)) != -1) {
        switch (opt) {
            case 'a': args_info -> algorithm = optarg;
                break;
            case 'p': 
                printf("Process raw info %s\n", optarg);
                args_info -> process = optarg;
                break; 
            case 'c': args_info -> compare = 1;
                break;
            case 'i': args_info -> input = optarg;
                break;
            case 'q': args_info -> quantum = atoi(optarg);
                break;
            case 'm': args_info -> mlfq_config = optarg;
                break;
            default:
                perror("Parsed unknown flag");
        }
    }

    printf("Exiting args");//DEBUG
    return args_info;
}