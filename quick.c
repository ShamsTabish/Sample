/* ASSIGNMENT NO : quick sort */
/* NAME: arushi kaul*/
/* ROLL NO:2603*/  

#include<stdio.h>


void display(int a[20],int n)
{
	int i;
  	for(i=0;i<n;i++)
 	{
 	     printf("%d",a[i]);
 	}
 }
 
 int sort(int a[20],int m,int n)
 {
    int p,temp,i,j;
    p=a[m];
    i=m+1;
    do
     {	 	while((a[i]<p)&&(i<n))	/* checking from right side */
       		{ i++;
     		}
     	    
     	     for(j=n-1;a[j]>p;j--); /* checking elements from left */
       		
       		
       		if(i<j)
        	{ temp=a[i];
       		  a[i]=a[j];
          	  a[j]=temp;
        	}
     }	while(i<j);
     a[i]=a[j];
     a[j]=p;     	/*swapping with the pivot */
     return j;
   }
       
void quicksort(int a[20],int m,int n)
{ 
    int j=0;
    j=sort(a,m,n);
	if(m<j)
    quicksort(a,m,j);
	if(j<n-1)
    quicksort(a,j+1,n);
    
 }
 

void main()
 { 
	int a[20];
    int m=0,u=0,i=0,n=0;
    m=0;
   
     printf(" enter the size of an array \n");
     scanf("%d",&n);
	u=n-1;
    printf(" enter the array of integers");
 	  for(i=0;i<n;i++)
 	   {
 	     scanf("%d",&a[i]);
 	   }
    quicksort(a,m,n);
    display(a,n);
    
   }
    
