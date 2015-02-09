#include<stdio.h>
#include<malloc.h>
int main(){
	char str[20]="Tango";
	char st[20]="hi";
	const char * p=str;
//	p=malloc(20);
//	p=st;	
//	st[0]='M';
	printf("%c is the result", str+2);
	return 0;
}
