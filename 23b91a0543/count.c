#include<stdio.h>
int main()
{
FILE *f1;
f1 = fopen("pqr.txt","r");
if(f1==NULL)
{
printf("file not found ");
return 0;
}
char ch;
int c=0,s=0,n=0;
while((ch=fgetc(f1))!=EOF)
{
c++;
if(ch=='\n')
n++;
if(ch==32)
	s++;
	
}
printf("the total number if characters with spaces %d\n",c);
printf("the total number if characters with out  spaces %d\n",c-s-n);
printf("just spaces %d\n",s);
printf("just nexts %d\n",n);
return 0;
}
