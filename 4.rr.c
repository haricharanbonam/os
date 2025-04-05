#include <stdio.h>

#define MAX 10 


void roundRobin(int processes[], int n, int bt[], int quantum) {
    int wt[n], tat[n], rem_bt[n], completion_time[n];
    int ganttChart[MAX][2];  
    int time = 0, index = 0; 

    for (int i = 0; i < n; i++) {
        rem_bt[i] = bt[i];
    }

    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0;
                if (rem_bt[i] > quantum) {
                    rem_bt[i] -= quantum;
                    ganttChart[index][0] = processes[i];
                    ganttChart[index][1] = quantum;
                    index++;
                    time += quantum;
                } else {
                    ganttChart[index][0] = processes[i];
                    ganttChart[index][1] = rem_bt[i];
                    index++;
                    time += rem_bt[i];
                    completion_time[i] = time;  
                    rem_bt[i] = 0;
                }
            }
        }
        if (done) break; 
    }


    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        tat[i] = completion_time[i];  
        wt[i] = tat[i] - bt[i];  
        total_wt += wt[i];
        total_tat += tat[i];
    }


    printf("\nGantt Chart:\n");
    for (int i = 0; i < index; i++) {
        printf("\t| P%d ", ganttChart[i][0]);
    }
    int total_time = 0;

        
printf("\n");
    printf("0  ");
    for (int i = 0; i < index; i++) {
        total_time += ganttChart[i][1];
        printf("\t%d", total_time);
    }
    printf("\nSimplified Gant Chart \n");
    int k=0;
   /* for(int i=0;i<index;i++)
    {
    	int j=i+1;
    	int key=ganttChart[i][0];
    	int sum=ganttChart[i][1];
    	while(key==ganttChart[j][0])
    	{
    		j=j+1;
    		i=i+1;
    		sum+=ganttChart[j][1];
	}
	ganttChart[k][0]=key;
	ganttChart[k][1]=sum;
	k++;
    }*/
    int sum=0;
     for(int i=0;i<index-1;i++)
    {
    	int j=i+1;	
    	int key=ganttChart[i][0];
    	sum+=ganttChart[i][1];
    	while(key==ganttChart[j][0])
    	{
    		sum+=ganttChart[j][1];
    		j=j+1; 
    		i=i+1;
	}
	ganttChart[k][0]=key;
	ganttChart[k][1]=sum;
	k++;
    }
    /*
    for(int i=0;i<k;i++)
    {
    	printf("%d\n",ganttChart[i][0]);
    }
        for(int i=0;i<k;i++)
    {
    	printf("%d\n",ganttChart[i][1]);
    }*/
        printf("\nSimplified Gant Chart \n");
        for (int i = 0; i < k; i++) {
        printf("\t| P%d ", ganttChart[i][0]);
    } 
    total_time = 0;      
printf("\n");
    printf("0  ");      
    for (int i = 0; i < k; i++) {
 
        printf("\t%d", ganttChart[i][1]);
    }
    

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
    }


    printf("\nAverage Waiting Time: %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_tat / n);
}

int main() {
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], bt[n]; 
    for (int i = 0; i < n; i++) {
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &bt[i]);
        processes[i] = i + 1; 
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);
    roundRobin(processes, n, bt, quantum);

    return 0;
}

