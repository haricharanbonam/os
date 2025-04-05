#include<stdio.h>
struct Student
{
	char name[20];
	char branch[20];
	char  loc[20];
};
int main(){
	FILE *f1;
	f1=fopen("student.txt","r");
	struct Student st;
	while((fscanf(f1,"%s %s %s\n",st.name,st.branch,st.loc))!=EOF)
	{
	printf("%s %s %s\n",st.name,st.branch,st.loc);
	}
return 0;
}
