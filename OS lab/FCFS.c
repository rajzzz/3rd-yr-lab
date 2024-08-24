#include <stdio.h>
#include <stdlib.h>

typedef struct process
{
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
} process;

void getProcessInfo(process p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival time of process %d: ", i + 1);
        scanf("%d", &p[i].arrival_time);
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &p[i].burst_time);
        p[i].pid = i + 1;
    }
}

// function to sort the processes based on arrival time in ascending order for easy processing in FCFS
// NOT THE MOST EFFICIENT WAY TO SORT but it works
void sort(process p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (p[i].arrival_time > p[j].arrival_time)
            {
                process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    process p[n];
    getProcessInfo(p, n);
    sort(p, n);
    int current_time = 0;
    for (int i = 0; i < n; i++)
    {
        if (current_time < p[i].arrival_time)
        {
            // because we have already sorted the processes based on arrival time, we can just set the current time to the arrival time of the next process
            current_time = p[i].arrival_time;
        }

        if (i == 0)
        {
            p[i].completion_time = current_time + p[i].burst_time;
        }
        else
        {
            // p[i].completion_time = p[i - 1].completion_time + p[i].burst_time;
            // OR
            p[i].completion_time = current_time + p[i].burst_time;
        }
        current_time = p[i].completion_time;
        p[i].turn_around_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turn_around_time - p[i].burst_time;
    }

    printf("\n------------------\n");

    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].completion_time, p[i].turn_around_time, p[i].waiting_time);
    }

    return 0;
}