
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// round robin

typedef struct process
{
    int arrival_time;
    int burst_time;
    int completion_time;
    int remaining_time;
    int turn_around_time;
    int waiting_time;

} process;

void getProcessinfo(process p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival time and burst time of process %d: ", i + 1);
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
        p[i].remaining_time = p[i].burst_time;
    }
}

void roundRobin(int n, process p[n], int time_quantum)
{
    int current_time = 0;
    int completion = 0;
   
    bool executed_in_this_cycle;

    while (completion < n)
    {
        executed_in_this_cycle = false; 
        for (int i = 0; i < n; i++)
        {
            if (p[i].arrival_time <= current_time && p[i].remaining_time > 0)
            {
                executed_in_this_cycle = true; 
                if (p[i].remaining_time > time_quantum)
                {
                    p[i].remaining_time -= time_quantum;
                    current_time += time_quantum;
                }
                else
                {
                    current_time += p[i].remaining_time;
                    p[i].completion_time = current_time;
                    p[i].remaining_time = 0;
                    completion++;
                }
            }
        }

        if (!executed_in_this_cycle)
        {
            current_time++;  
        }
    }
    for (int i = 0; i < n; i++)
    {
        p[i].turn_around_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turn_around_time - p[i].burst_time;
    }

    
}



int main()
{

    int n;
    float avg_tat, avg_wt;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    process p[n];
    getProcessinfo(p, n);

    roundRobin(n, p, 2);


    for (int i = 0; i < n; i++)
    {
        avg_wt += p[i].waiting_time;
        avg_tat += p[i].turn_around_time;
    }
    printf("Process No.\t  Arrival Time\t    Burst Time\t    Completion Time\t   Turn Around Time\t Waiting Time");
    for (int i = 0; i < n; i++)
    {
        printf("\n P%d\t\t      %d\t\t      %d\t\t\t     %d\t\t      %d\t\t\t        %d", i + 1, p[i].arrival_time, p[i].burst_time, p[i].completion_time, p[i].turn_around_time, p[i].waiting_time);
    }

    printf("\n");
    printf("\nAverage Turn-Around Time = %f units ", avg_tat / n);
    printf("\nAverage Waiting Time = %f units ", avg_wt / n);


    return 0;
}