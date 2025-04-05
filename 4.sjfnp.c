
#include<stdio.h>
int main() {
    int size, b[10], w[10], t[10], p[10];
    int sum_t = 0, sum_w = 0;
    float avg_w, avg_t;
    printf("Enter number of processes: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        printf("\nProcess %d burst time: ", i + 1);
        scanf("%d", &b[i]);
        p[i] = i + 1;
    }
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (b[j] > b[j + 1]) {
                int temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;

                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    w[0] = 0;
    for (int i = 1; i < size; i++) {
        w[i] = w[i - 1] + b[i - 1];
    }

    t[0] = b[0];
    for (int i = 1; i < size; i++) {
        t[i] = t[i - 1] + b[i];
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", p[i], b[i], w[i], t[i]);
        sum_t += t[i];
        sum_w += w[i];
    }

    avg_w = (float)sum_w / size;
    avg_t = (float)sum_t / size;

    printf("\nAverage Waiting Time: %.2f", avg_w);
    printf("\nAverage Turnaround Time: %.2f\n", avg_t);

    printf("\nGantt Chart:\n|");
    for (int i = 0; i < size; i++) {
        printf(" p%d |", p[i]);
    }

    printf("\n0");
    for (int i = 0; i < size; i++) {
        printf("    %d", t[i]);
    }
    printf("\n");

    return 0;
}
