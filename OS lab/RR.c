#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
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

void roundRobin(process p[], int n, int time_quantum)
{
    int current_time = 0;
    int completed = 0;
    int queue[n];
    int front = 0;
    int rear = 0;
    bool in_queue[n];
    for (int i = 0; i < n; i++)
    {
        in_queue[i] = false;
    }

    queue[rear++] = 0;
    in_queue[0] = true;

    while (completed < n)
    {
        int pid = queue[front++];
        if (front == n)
            front = 0;

        for (int i = 0; i < n; i++)
        {
            if (p[i].pid == pid)
            {
                if (p[i].remaining_time <= time_quantum)
                {
                    current_time += p[i].remaining_time;
                    p[i].remaining_time = 0;
                    p[i].completion_time = current_time;
                    p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
                    p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
                    completed++;
                }
                else
                {
                    current_time += time_quantum;
                    p[i].remaining_time -= time_quantum;
                }

                // Check for new arrivals and add them to the queue
                for (int j = 0; j < n; j++)
                {
                    if (p[j].arrival_time <= current_time && p[j].remaining_time > 0 && !in_queue[j])
                    {
                        queue[rear++] = p[j].pid;
                        if (rear == n)
                            rear = 0;
                        in_queue[j] = true;
                    }
                }

                // Re-queue the current process if it has remaining time
                if (p[i].remaining_time > 0)
                {
                    queue[rear++] = p[i].pid;
                    if (rear == n)
                        rear = 0;
                }
                break;
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

    int time_quantum;
    printf("Enter time quantum: ");
    scanf("%d", &time_quantum);

    roundRobin(p, n, time_quantum);

    printf("\n------------------\n");
    printf("Process\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", p[i].pid + 1, p[i].arrival_time, p[i].burst_time, p[i].completion_time, p[i].turnaround_time, p[i].waiting_time);
    }

    return 0;
}