

#include <stdio.h>

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n], rt[n];
    int current_time = 0, completed = 0;
    float avg_tat = 0, avg_wt = 0;


    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    while (completed < n) {
        int shortest_job = -1, shortest_time = 9999;

        for (int j = 0; j < n; j++) {
            if (at[j] <= current_time && rt[j] > 0 && rt[j] < shortest_time) {
                shortest_time = rt[j];
                shortest_job = j;
            }
        }

        if (shortest_job == -1) {
            current_time++;
            continue;
        }

        rt[shortest_job]--;
        current_time++;

        if (rt[shortest_job] == 0) {
            completed++;
            ct[shortest_job] = current_time;
            tat[shortest_job] = ct[shortest_job] - at[shortest_job];
            wt[shortest_job] = tat[shortest_job] - bt[shortest_job];

            avg_tat += tat[shortest_job];
            avg_wt += wt[shortest_job];
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time: %.2f\n", avg_tat / n);
    printf("Average Waiting Time: %.2f\n", avg_wt / n);
    
    printf("\nGantt Chart:\n");

    int start_time = 0;
    printf("    ");
    for (int i = 0; i < n; i++) {
        printf("| P%d ", i+1);
    }
    printf("|\n");

    printf("0   ");
    for (int i = 0; i < n; i++) {
        start_time += bt[i];
        printf("    %d ", start_time);
    }
    printf("\n");


    return 0;
}

