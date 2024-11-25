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
} process;

void getProcessInfo(process p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival time and burst time of process %d: ", i + 1);
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
        p[i].pid = i + 1;
    }
}

void sortByArrivalTime(process p[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].arrival_time > p[j + 1].arrival_time)
            {
                process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void calculateCompletionTime(process p[], int n)
{
    process q[n];
    int front = 0, rear = 1;
    int time = p[0].arrival_time;
    q[front] = p[0];
    int i = 1;

    while (i < n || front != rear)
    {
        time += q[front].burst_time;
        for (int k = 0; k < n; k++)
        {
            if (p[k].pid == q[front].pid)
            {
                p[k].completion_time = time;
                break;
            }
        }

        while (i < n && p[i].arrival_time <= time)
        {
            q[rear] = p[i];
            rear++;
            i++;
        }

        front++;

        for (int j = front + 1; j < rear; j++)
        {
            if (q[front].burst_time > q[j].burst_time)
            {
                process temp = q[front];
                q[front] = q[j];
                q[j] = temp;
            }
        }
    }
}

void calculateTurnAroundTimeAndWaitingTime(process p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i].turn_around_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turn_around_time - p[i].burst_time;
    }
}

void sortByProcessID(process p[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].pid > p[j + 1].pid)
            {
                process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void printProcessInfo(process p[], int n)
{   float avg_wt = 0.0;
    float avg_tat = 0.0;

    for (int i = 0; i < n; i++)
    {
        avg_wt += p[i].waiting_time;
        avg_tat += p[i].turn_around_time;
    }
    printf("\n");
    printf("Process No.\t   Arrival Time\t   Burst Time \t   Completion Time\t   TurnAround Time\t Waiting Time\t");
    for (int i = 0; i < n; i++)
    {
        printf("\nP%d\t\t    %d\t\t    %d\t\t          %d\t\t          %d\t\t        %d\t", i + 1, p[i].arrival_time, p[i].burst_time, p[i].completion_time, p[i].turn_around_time, p[i].waiting_time);
    }

    printf("\n");
    printf("\nAverage Turn-Around Time = %f units ", avg_tat / n);
    printf("\nAverage Waiting Time = %f units ", avg_wt / n);
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    process p[n];
    getProcessInfo(p, n);
    sortByArrivalTime(p, n);
    calculateCompletionTime(p, n);
    calculateTurnAroundTimeAndWaitingTime(p, n);
    sortByProcessID(p, n);
    printProcessInfo(p, n);

    return 0;
}

















