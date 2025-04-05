#include <stdio.h>

int main() {
    int n, i, time = 0, completed = 0, min_pri, idx;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int processes[n], at[n], bt[n], pri[n], wt[n], tat[n], remaining[n], ct[n];
    float avg_wt = 0, avg_tat = 0;

    printf("Enter Process IDs: ");
    for (i = 0; i < n; i++)
        scanf("%d", &processes[i]);

    printf("Enter Arrival Times: ");
    for (i = 0; i < n; i++)
        scanf("%d", &at[i]);

    printf("Enter Burst Times: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        remaining[i] = bt[i];
    }

    printf("Enter Priorities: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pri[i]);

    while (completed < n) {
        min_pri = 9999;
        idx = -1;

        for (i = 0; i < n; i++) {
            if (remaining[i] > 0 && at[i] <= time && pri[i] < min_pri) {
                min_pri = pri[i];
                idx = i;
            }
        }

        if (idx == -1) {
            time++;
            continue;
        }

        remaining[idx]--;
        time++;

        if (remaining[idx] == 0) {
            completed++;
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
        }
    }

    printf("\nProcess\tAT\tPriority\tBT\tCT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t\t%d\t%d\t%d\t%d\n", processes[i], at[i], pri[i], bt[i], ct[i], wt[i], tat[i]);
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("\nAverage Waiting Time: %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat / n);

    printf("\nGantt Chart:\n");

    int start_time = 0;
    printf("    ");
    for (i = 0; i < n; i++) {
        printf("| P%d ", processes[i]);
    }
    printf("|\n");

    printf("0   ");
    for (i = 0; i < n; i++) {
        start_time += bt[i];
        printf("    %d ", start_time);
    }
    printf("\n");


    return 0;
}

