#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
        printf("Enter the arrival time of process %d: ", i + 1);
        scanf("%d", &p[i].arrival_time);
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &p[i].burst_time);
        printf("Enter the priority of process %d: ", i + 1);
        scanf("%d", &p[i].priority);
        p[i].pid = i + 1;
    }
}

// we will sort the processes based on arrival time
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
            else if (p[i].arrival_time == p[j].arrival_time)
            {
                if (p[i].priority < p[j].priority)
                {
                    process temp = p[i];
                    p[i] = p[j];
                    p[j] = temp;
                }
            }
        }
    }
}

// NOTE : We will consider higher numerical value as higher priority

int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    process p[n];
    getProcessInfo(p, n);
    sort(p, n);

    int current_time = p[0].arrival_time;
    int queue[n];
    int front = -1, rear = -1;
    int completed = 0;
    bool in_queue[n];

    for (int i = 0; i < n; i++)
    {
        in_queue[i] = false;
    }

    while (completed < n)
    {

        for (int i = 0; i < n; i++)
        {
            if (p[i].arrival_time <= current_time && !in_queue[i] && !p[i].completed)
            {
                if (front == -1)
                {
                    front = 0;
                }
                rear++;
                queue[rear] = i;
                in_queue[i] = true;
                if (rear == n)
                    rear = 0;
            }
        }

        int max = -1;
        for (int i = front; i <= rear; i++)
        {
            if (in_queue[queue[i]])
            {
                if (max == -1)
                {
                    max = queue[i];
                }
                else if (p[queue[i]].priority > p[max].priority)
                {
                    max = queue[i];
                }
            }
        }

        current_time += p[max].burst_time;
        p[max].completion_time = current_time;
        p[max].turn_around_time = p[max].completion_time - p[max].arrival_time;
        p[max].waiting_time = p[max].turn_around_time - p[max].burst_time;
        completed++;
        p[max].completed = true;
        in_queue[max] = false;
    }

    printf("\n---------------------\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].completion_time, p[i].turn_around_time, p[i].waiting_time);
    }
    return 0;
}