#include <stdio.h>

// first come first serve

int main()
{
    int n;

    printf("Enter the number of processes : ");
    scanf("%d", &n);
    printf("\n");
    int arrival_time[n];
    int burst_time[n];
    int completion_time[n];
    int turnaround_time[n];
    int waiting_time[n];
    int current_time = 0;
    float avg_wt = 0.0;
    float avg_tat = 0.0;

    for (int i = 0; i < n; i++)
    {
        printf("Enter Arrival time and Burst time for process P%d : ", i + 1);
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
    }

    for (int i = 0; i < n; i++)
    {

        if (current_time < arrival_time[i])
        {
            current_time = arrival_time[i];
        }
        current_time += burst_time[i];
        completion_time[i] = current_time;
        turnaround_time[i] = completion_time[i] - arrival_time[i];
        waiting_time[i] = turnaround_time[i] - burst_time[i];
    }

    for (int i = 0; i < n; i++)
    {
        avg_wt += waiting_time[i];
        avg_tat += turnaround_time[i];
    }

    printf("\n");
    printf("Process No.\t   Arrival Time\t   Burst Time \t   Completion Time\t   TurnAround Time\t Waiting Time\t");
    for (int i = 0; i < n; i++)
    {
        printf("\nP%d\t\t    %d\t\t    %d\t\t          %d\t\t          %d\t\t        %d\t", i + 1, arrival_time[i], burst_time[i], completion_time[i], turnaround_time[i], waiting_time[i]);
    }

    printf("\n");
    printf("\nAverage Turn-Around Time = %f units ", avg_tat / n);
    printf("\nAverage Waiting Time = %f units ", avg_wt / n);

    return 0;
}