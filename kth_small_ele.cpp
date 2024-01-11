
#include<stdio.h>
#include<stdlib.h>

int partition(int arr[],int left,int right)
{
	int pivot=arr[right];
	int i=left-1;
	int j;
	for(j=left;j<right;j++)
	{
		if(arr[j]<=pivot)
		{
			i++;
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	int temp=arr[i+1];
	arr[i+1]=arr[right];
	arr[right]=temp;
	return i+1;
}

int smallest_recursive(int arr[],int left,int right,int k)
{
	if(k>0 && k<=(right-left+1))
	{
	int pivot_index=partition(arr,left,right);
	if (pivot_index - left == k - 1) {
            return arr[pivot_index];
        }
	if( pivot_index-left > k-1)
	{
		return smallest_recursive(arr,left,pivot_index-1,k);
	}
	return smallest_recursive(arr,pivot_index+1,right,k-pivot_index+left-1);
}
return -1;
}

int smallest_element(int arr[],int n,int k)
{
	if(k>0 && k<=n)
	{
		return smallest_recursive(arr,0,n-1,k);
	}
	else
	{
		return -1;
	}
}
int main()
{
	int arr[]={7,10,4,3,20,15};
	int k=3;
	int n=sizeof(arr)/sizeof(arr[0]);
	int res=smallest_element(arr,n,k);
	if (res != -1) {
        printf("The %dth smallest element is: %d\n", k, res);
    } else {
        printf("Invalid value of k\n");
    }
    return 0;
}
