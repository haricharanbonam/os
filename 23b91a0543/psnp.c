#include<stdio.h>
int main() {
    int size, bt[10], wt[10], tat[10], p[10], pri[10];
    int sum_t = 0, sum_w = 0;
    float avg_w, avg_t;
    printf("Enter number of processes: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        printf("\nP %d bt: ", i + 1);
        scanf("%d", &bt[i]);
        printf("Process %d priority: ", i + 1);
        scanf("%d", &pri[i]);
        p[i] = i + 1;
    }

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (pri[j] > pri[j + 1]) {
                int temp = pri[j];
                pri[j] = pri[j + 1];
                pri[j + 1] = temp;

                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    wt[0] = 0;
    for (int i = 1; i < size; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    tat[0] = bt[0];
    for (int i = 1; i < size; i++) {
        tat[i] = tat[i - 1] + bt[i];
    }

    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], pri[i], wt[i], tat[i]);
        sum_t += tat[i];
        sum_w += wt[i];
    }

    avg_w = (float)sum_w / size;
    avg_t = (float)sum_t / size;

    printf("\nAverage Waiting Time: %.2f", avg_w);
    printf("\nAverage Turnaround Time: %.2f\n", avg_t);

    printf("\nGantt Chart:\n");

    int start_time = 0;
    printf("    ");
    int i;
    for (i = 0; i < size; i++) {
        printf("| P%d ", p[i]);
    }
    printf("|\n");

    printf("0   ");
    for (i = 0; i < size; i++) {
        start_time += bt[i];
        printf("    %d ", start_time);
    }
    printf("\n");

    return 0;
}


