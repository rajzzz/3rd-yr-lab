/* #include <stdio.h>
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
    int time_quantum = 2;
    int current_time = 0;
    int queue[n * n];
    int front = 0;
    int rear = 0;

    if (current_time < p[0].arrival_time)
    {
        printf("1\n");
        current_time = p[0].arrival_time;
    }
    printf("2\n");
    queue[front] = p[0].pid;

    if (p[0].burst_time <= time_quantum)
    {
        current_time += p[0].burst_time;
        p[0].completion_time = current_time;
        p[0].turn_around_time = p[0].completion_time - p[0].arrival_time;
        p[0].waiting_time = p[0].turn_around_time - p[0].burst_time;
        front++;
        rear = front;
        printf("3\n");
    }
    // p[0].burst_time > time_quantum
    else
    {
        printf("4\n");
        current_time += time_quantum;
        p[0].burst_time -= time_quantum;

        for (int i = 1; i < n; i++)
        {
            printf("5\n");
            if (p[i].arrival_time <= current_time)
            {

                queue[++rear] = p[i].pid;
                printf("6\n");
                // rear++;
            }
        }
        printf("7\n");
        queue[++rear] = p[0].pid;
        front++;

        while (front != rear)
        {
            printf("8\n");
            int pid = queue[front];
            for (int i = 0; i < n; i++)
            {
                printf("9\n");
                if (p[i].pid == pid)

                {
                    printf("10\n");
                    if (p[i].burst_time <= time_quantum)
                    {
                        printf("11\n");
                        current_time += p[i].burst_time;
                        p[i].completion_time = current_time;
                        p[i].turn_around_time = p[i].completion_time - p[i].arrival_time;
                        p[i].waiting_time = p[i].turn_around_time - p[i].burst_time;
                        front++;
                    }
                    else
                    {
                        printf("12\n");
                        current_time += time_quantum;
                        p[i].burst_time -= time_quantum;
                        for (; i < n; i++)
                        {
                            printf("13\n");
                            if (p[i + 1].arrival_time <= current_time)
                            {
printf("14\n");
                                queue[++rear] = p[i].pid;
                                // rear++;
                            }
                        }
                        printf("15\n");
                        queue[++rear] = p[i].pid;
                        front++;
                    }
                }
            }
        }
    }
    printf("16\n");

    printf("\n------------------\n");

    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].completion_time, p[i].turn_around_time, p[i].waiting_time);
    }

    return 0;
} */

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