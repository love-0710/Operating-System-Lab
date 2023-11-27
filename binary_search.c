#include<stdio.h>
#include"binary.h"
void main()
{
	int arr[20],i,total;
	printf("Enter the no of elements:");
	scanf("%d",&total);
	printf("Entet the elements:");
	for(i=0;i<total;i++)
	{
		scanf("%d",&arr[i]);
	}
	binary_search(arr,total);
}

