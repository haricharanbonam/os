#include<stdio.h>
#include<string.h>
struct Student
{
	char name[10];
	char branch[5];
	char  loc[20];
};
int main(){
	FILE *f1;
	f1=fopen("student.txt","r");
	struct Student st;
	while((fscanf(f1,"%s %s %s\n",st.name,st.branch,st.loc))!=EOF)
	{
	int a = strlen(st.name);
	int b= strlen(st.branch);
	int c = strlen(st.loc);
	printf("%d",a+b+c);
	printf("#");
	printf("%s ",st.name);
	printf("#");
	printf("%s ",st.branch);
	printf("#");
	printf("%s",st.loc);
	printf("#");
	printf("\n");
	}
return 0;
}
