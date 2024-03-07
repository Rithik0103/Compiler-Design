#include<stdio.h> 
#include<conio.h> 
#include<ctype.h>
int main()
{
	char a[10]; 
	int flag,i=1; 
	printf("\n Enter an identifier:"); 
	gets(a);
	if(isalpha(a[0]))
		flag=1; 
	else
		flag=0; 

	if(flag==1)
		printf("\n Valid identifier");
	else
	printf("nvalid, not a identifier");
}
