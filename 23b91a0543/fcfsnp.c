#include <stdio.h>

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int p[n], at[n], bt[n], ct[n], tat[n], wt[n];
    float total_tat = 0, total_wt = 0;
    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        p[i] = i + 1;

        scanf("%d %d", &at[i], &bt[i]);
    }


    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                int temp = at[j]; at[j] = at[j + 1]; at[j + 1] = temp;
                temp = bt[j]; bt[j] = bt[j + 1]; bt[j + 1] = temp;
                temp = p[j]; p[j] = p[j + 1]; p[j + 1] = temp;
            }
        }
    }

    int current_time = 0;

    for (int i = 0; i < n; i++) {
        if (current_time < at[i]) {
            current_time = at[i];
        }
        current_time += bt[i];
        ct[i] = current_time;
    }

    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        total_tat += tat[i];
        total_wt += wt[i];
    }


    printf("\nProcess  Arrival  Burst  Completion  Turnaround  Waiting\n");
    for (int i = 0; i < n; i++) {
        printf("%6d %8d %6d %11d %11d %8d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time: %.2f", total_tat / n);
    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);

    
 printf("\nGantt Chart:\n");

    int start_time = 0;
    printf("    ");
    for (int i = 0; i < n; i++) {
        printf("| P%d ", p[i]);
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
