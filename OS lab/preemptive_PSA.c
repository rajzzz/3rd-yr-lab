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
        printf("Enter the arrival time of process %d: ", i + 1);
        scanf("%d", &p[i].arrival_time);
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &p[i].burst_time);
        printf("Enter the priority of process %d: ", i + 1);
        scanf("%d", &p[i].priority);
        p[i].pid = i + 1;
        p[i].remaining_time = p[i].burst_time; // Initialize remaining time
        p[i].completed = false;
    }
}

int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    process p[n];
    getProcessInfo(p, n);

    int current_time = 0;
    int completed = 0;
    int last_process = -1; // To track last executed process to avoid unnecessary switches

    while (completed < n)
    {
        int highest_priority = INT_MAX;
        int next_process = -1;

        // Find the process with the highest priority (lower value) that has arrived and is not completed
        for (int i = 0; i < n; i++)
        {
            if (p[i].arrival_time <= current_time && !p[i].completed && p[i].priority < highest_priority && p[i].remaining_time > 0)
            {
                highest_priority = p[i].priority;
                next_process = i;
            }
        }

        if (next_process != -1) // A process is available to execute
        {
            if (last_process != next_process) {
                printf("Switching to process %d at time %d\n", p[next_process].pid, current_time);
                last_process = next_process;
            }
            // Execute the next process for 1 unit of time
            p[next_process].remaining_time--;
            current_time++;

            // If the process completes its burst time, mark it as completed
            if (p[next_process].remaining_time == 0)
            {
                p[next_process].completed = true;
                p[next_process].completion_time = current_time;
                p[next_process].turn_around_time = p[next_process].completion_time - p[next_process].arrival_time;
                p[next_process].waiting_time = p[next_process].turn_around_time - p[next_process].burst_time;
                completed++;
            }
        }
        else // No process available, move time forward
        {
            current_time++;
        }
    }

    printf("\n---------------------\n");
    printf("PID\tAT\tBT\tPriority\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].priority, p[i].completion_time, p[i].turn_around_time, p[i].waiting_time);
    }
    return 0;
}
