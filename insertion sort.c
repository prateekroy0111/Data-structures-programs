#include <stdio.h> 
#define MAX 30

int main() 
{ 
	int i,key,j,n,arr[MAX]; 
	
	printf("Enter number of elements:");
	scanf("%d",&n);
		
	printf("Enter array elements:\n");
	for(i=0;i<n;++i)
		scanf("%d",&arr[i]);
		
	for (i = 1; i < n; i++) 
	{ 
		key = arr[i]; 
		j = i - 1; 
		while (j >= 0 && arr[j] > key) 
		{ 
			arr[j + 1] = arr[j]; 
			j = j - 1; 
		} 
		arr[j + 1] = key; 
	} 
	
	printf("\nArray after insertion sort:\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
		
	return 0; 
} 

