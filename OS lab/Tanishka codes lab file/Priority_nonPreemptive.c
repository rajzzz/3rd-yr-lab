#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

typedef struct process
{
    int pid;
    int arrival_time;
    int burst_time;
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
        scanf("%d %d %d", &p[i].arrival_time, &p[i].burst_time, &p[i].priority);
        p[i].pid = i + 1;
        p[i].completed = false;
    }
}

int main()
{
    printf("\nLOWER PRIORITY VALUE HAS HIGHER PRIORITY\n");
    int n;
    float avg_tat = 0.0, avg_wt = 0.0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    process p[n];
    getProcessInfo(p, n);

    int current_time = 0, completed = 0;

    while (completed < n)
    {
        int highest_priority_index = -1;
        int highest_priority = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (p[i].arrival_time <= current_time && !p[i].completed)
            {
                if (p[i].priority < highest_priority)
                {
                    highest_priority = p[i].priority;
                    highest_priority_index = i;
                }
                else if (p[i].priority == highest_priority && p[i].arrival_time < p[highest_priority_index].arrival_time)
                {
                    highest_priority_index = i;
                }
            }
        }

        if (highest_priority_index != -1)
        {
            int idx = highest_priority_index;
            current_time += p[idx].burst_time;
            p[idx].completion_time = current_time;
            p[idx].turn_around_time = p[idx].completion_time - p[idx].arrival_time;
            p[idx].waiting_time = p[idx].turn_around_time - p[idx].burst_time;
            p[idx].completed = true;
            completed++;
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
    printf("Process ID\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnAround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d\t\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].priority, p[i].completion_time, p[i].turn_around_time, p[i].waiting_time);
    }

    printf("\n");
    printf("\nAverage Turn-Around Time = %.2f units ", avg_tat / n);
    printf("\nAverage Waiting Time = %.2f units ", avg_wt / n);
    return 0;
}
