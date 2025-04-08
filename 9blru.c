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

int least(int fr[],int a[],int curr)
{
    int index=-1;
    int replace=-1;
    for(int j=0;j<SIZE;j++)
    {
        for(int i=curr;i>=0;i--)
        {
            if(fr[j]==a[i])
            {
                if(index==-1 || i<index )
                {
                    index=i;
                    replace=j;
                    break;
                }
            }
        }
    }
    return replace;
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
            int r = least(fr,a,i);
            fr[r]=a[i];
        }

        tot++; 
        display(fr);
    }

    printf("Total Page Faults: %d\n", tot);
    printf("Total   Hits : %d\n", hit);
    return 0;
}
