#include<stdio.h>
#include<stdbool.h>

#define SIZE 3 

bool found(int arr[], int k) {
    for(int i = 0; i < SIZE; i++) {
        if(arr[i] == k) {
            return true;
        }
    }
    return false;
}

void display(int arr[]) {
    for(int i = 0; i < SIZE; i++) {
        if(arr[i] != -1)
            printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int a[100];
    int n;
    int hit=0;
    
    printf("Enter number of pages: ");
    scanf("%d", &n);
    
    printf("Enter reference string: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int fr[SIZE];
    for(int i = 0; i < SIZE; i++) {
        fr[i] = -1;
    }

    int empty = SIZE;    
    int tot = 0;       
    int index = 0;     

    for(int i = 0; i < n; i++) {
        if(found(fr, a[i])) {
            hit++;
            continue;
        }
        if(empty > 0) {
            fr[SIZE - empty] = a[i]; 
            empty--;
        } else {
            fr[index] = a[i]; 
            index = (index + 1) % SIZE;
        }

        tot++; 
        display(fr);
    }

    printf("Total Page Faults: %d\n", tot);
    printf("Total   Hits : %d\n", hit);
    return 0;
}
