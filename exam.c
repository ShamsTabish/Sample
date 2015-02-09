#include<stdio.h>
int l(int i){
	++i;
	printf("\nLeft Called %d\n",i);
	return i;
}

int m(int i){
	++i;
	printf("\nMid Called %d\n",i);
	return i;
}

int r(int i){
	++i;
	printf("\nRight Called %d\n",i);
	return i;
}
int all(int i){
	
	printf("\nAll Called %d\n",i);
	return i;
}

int main(){
	int i=4,x=4;
//	i=i++;
//	x=++x;
//	x=++i + ++i + ++i;
	x=(i=l(i))+(all((i=m(i))+(i=r(i))));
	printf("i=%d, x=%d",i,x);
	return 0;
}
