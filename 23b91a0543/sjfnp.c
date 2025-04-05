#include <stdio.h>

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int p[n],bt[n],tat[n],wt[n];
    float total_tat = 0, total_wt = 0;

    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
        scanf("%d",  &bt[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (bt[j] > bt[j + 1]) {
            int temp;
                temp = bt[j]; bt[j] = bt[j + 1]; bt[j + 1] = temp;
                temp = p[j]; p[j] = p[j + 1]; p[j + 1] = temp;
            }
        }
    }
    wt[0] = 0;
    total_wt+=wt[0];   
    for(int i=1;i<n;i++)
    {
    	wt[i]=wt[i-1]+bt[i-1];
    	   total_wt+=wt[i]; 
    }
     tat[0] = bt[0]; 
     total_tat+=tat[0];
    for (int i = 1; i < n; i++) {
	tat[i]=tat[i-1]+bt[i];
    }


    printf("\nProcess  Burst   Turnaround  Waiting\n");
    for (int i = 0; i < n; i++) {
        printf("%6d  %6d %11d %8d\n", p[i],bt[i],  tat[i], wt[i]);
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
