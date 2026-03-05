# CMSC 125 | CPU Scheduling (Lab 2)

## Contributors
Mark Leonel T. Misola (Xenon5443)\
Francis Eugene Kho Young (YoungFEK)

> [!NOTE]
> This project is still in development!

## Minor CPU Scheduler
| CPU Scheduling Algorithm | Description |
| --- | --- |
| First come first serve (FCFS) | Executes the job in order of arrival |
| Shortest Job first (SJF) | Executes the job according to burst time. Starts with the smallest job first |
| Shortest time to completion first (STCF) | Compares the remaining burst time of the current running job and the newly arrived job. Executes the job with a shorter burst time |
| Round Robin (RR) | Interrupts the current executing job when a job with a burst time shorter than the current burst time or the current job arrives |
| Multi-Level Feedback Queue (MLFQ) | In a nutshell, it separates jobs into multiple queues according to priority and length of jobs |

## CPU scheduling time metrics
| Scheduling metrics | Definition |
|---|---|
| Finish time | Point in time when the process finishes |
| Turnaround time | Time elapsed from arrival to completion |
| Response time | Time elapsed from arrival time to first response |
| Waiting time | Time elapsed from arrival time to finish time, excluding the burst time |

## Timeline
| Week Number | Objective |
|---|---|
| Week 1 | Initial commits from the specified folder structure and initial review of scheduling concepts |
| Week 2 | Initial testers and working prototype of minor CPU scheduling algorithms |
| Week 3 | Design and working prototype of MLFQ |
| Week 4 | Furnishing, refactores, code testing and final defense |