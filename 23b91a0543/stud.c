#include<stdio.h>
struct Student
{
	char name[20];
	char branch[20];
	char  loc[20];
};
int main(){
	FILE *f1;
	f1=fopen("student.txt","a");
	int n;
	printf("enter no of students : ");
	scanf("%d",&n);
	struct Student st[n];
	for(int i=0;i<n;i++)
	{
	printf("enter %d student details \n",i);
	printf("enter name :");
	scanf("%s",st[i].name);
	printf("enter branch :");
	scanf("%s",st[i].branch);
	printf("enter loc :"); 
	scanf("%s",st[i].loc);
	}
	char ch;
	for (int i=0;i<n;i++)
	{
	fprintf(f1,"%s %s %s\n",st[i].name,st[i].branch,st[i].loc);
	}
	printf("data entries saved succesfully");
return 0;
}
