#include<stdio.h>
#include<stdbool.h>
bool found(int arr[],int n,int k)
{
	for(int i=0;i<n;i++)
	{
		if(arr[i]==k)
		{
			return true;
		}
	}
	return false;
}
bool display(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int main()
{
	int a[100];
	int n;
	scanf("%d",&n);
	printf("enter ref string :");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	
	int fr[3];
	int empty=3;
	int tot=0;
	int index=0;
	for(int i=0;i<n;i++)
	{
		if(empty>0)
		{
			fr[3-empty]=a[i];
			empty--;
			tot++;
			display(fr,3-empty);
		}
		else
		{
			if(found(fr,3,a[i]))
			{
				continue;
			}
			else
			{
				fr[index]=a[i];
				display(fr,3);
				index=(index+1)%3;
				tot++;
				
			}
			
		}
	}
	printf("%d",tot);
}
