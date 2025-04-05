#include<stdio.h>
#include<string.h>
struct Student
{
	char name[10];
	char branch[5];
	char  loc[20];
};
int main(){
	FILE *f1;2
	f1=fopen("student.txt","r");
	struct Student st;
	while((fscanf(f1,"%s %s %s\n",st.name,st.branch,st.loc))!=EOF)
	{
	printf("%s",st.name);
	for(int i=strlen(st.name);i<10;i++)
	{
	printf(".");
	}
	printf(" ");
	printf("%s",st.branch);
	for(int i=strlen(st.branch);i<5;i++)
	{
	printf(".");
	}
	printf(" ");
	printf("%s",st.loc);
	for(int i=strlen(st.loc);i<20;i++)
	{
	printf(".");
	}
	printf(" ");
	printf("\n");
	}
return 0;
}
