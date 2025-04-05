#include<stdio.h>
int main()
{
FILE *f1;
FILE *f2;
f1=fopen("abc.txt","r");
if(f1==NULL)
{
	printf("file doesnt exist \n");
}
f2=fopen("pqr.txt","w");
char ch;
while((ch=fgetc(f1))!=EOF)
{
	fputc(ch,f2);
}
printf("file copying succesfull\n ");
return 0;
}
