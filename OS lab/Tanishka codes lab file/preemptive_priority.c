
//preemptive priority scheduling algorithm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct process
{
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
    int priority;
    bool completed;
} process;

void getProcessInfo(process p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter the Arrival time, Burst time and Priority of process %d: ", i + 1);
        scanf("%d %d %d", &p[i].arrival_time,&p[i].burst_time,&p[i].priority);
        p[i].pid = i + 1;
        p[i].remaining_time = p[i].burst_time; 
        p[i].completed = false;
    }
}

int main()
{
    printf("\nLOWER PRIORITY VALUE HAS HIGHER PRIORITY\n");
    int n;
    float avg_tat=0.0, avg_wt=0.0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    process p[n];
    getProcessInfo(p, n);

    int current_time = 0;
    int completed = 0;
    int last_process = -1; 

    while (completed < n)
    {
        int highest_priority = INT_MAX;
        int next_process = -1;

        
        for (int i = 0; i < n; i++)
        {
            if (p[i].arrival_time <= current_time && !p[i].completed && p[i].priority < highest_priority && p[i].remaining_time > 0)
            {
                highest_priority = p[i].priority;
                next_process = i;
            }
        }

        if (next_process != -1) 
        {
            if (last_process != next_process) {
                printf("Switching to process %d at time %d\n", p[next_process].pid, current_time);
                last_process = next_process;
            }
            
            p[next_process].remaining_time--;
            current_time++;

            
            if (p[next_process].remaining_time == 0)
            {
                p[next_process].completed = true;
                p[next_process].completion_time = current_time;
                p[next_process].turn_around_time = p[next_process].completion_time - p[next_process].arrival_time;
                p[next_process].waiting_time = p[next_process].turn_around_time - p[next_process].burst_time;
                completed++;
            }
        }
        else 
        {
            current_time++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        avg_wt += p[i].waiting_time;
        avg_tat += p[i].turn_around_time;
    }

    printf("\n---------------------------------------------------------------------------------------------------------\n");
    printf("Process ID\tArrival Time\t Burst Time\t  Priority\tCompletion Time\t TurnAround Time   Waiting Time\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d\t\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].priority, p[i].completion_time, p[i].turn_around_time, p[i].waiting_time);
    }

    printf("\n");
    printf("\nAverage Turn-Around Time = %f units ", avg_tat / n);
    printf("\nAverage Waiting Time = %f units ", avg_wt / n);
    return 0;
}