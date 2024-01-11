#include<stdio.h>
#include<stdlib.h>

void merge(int a[], int left, int mid, int right) {
 int n1=mid-left+1;
 int n2=right-mid;
 int L[n1],R[n2];
 for(int i=0;i<n1;i++)
 {
 	L[i]=a[left+i];
 }
 for(int j=0;j<n2;j++)
 {
 	R[j]=a[mid+1+j];
 }
 int i=0,j=0,k=left;
 while(i<n1&&j<n2)
{
	if(L[i]<R[j])
	{
		a[k]=L[i];
		i++;
	}
	else if(L[i]>R[j])
	{
		a[k]=R[j];
		j++;
	}
	else
	{
		a[k]=R[j];
		i++;
		j++;
	}
	k++;
}
while(i<n1)
{
	a[k]=L[i];
	i++;
	k++;
}
while(j<n2)
{
	a[k]=R[j];
	j++;
	k++;
}
}

void mergesort(int a[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergesort(a, left, mid);
        mergesort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

int main() {
    int a[] = {7, 10, 3, 4, 20, 15};
    int n = sizeof(a) / sizeof(a[0]);

    mergesort(a, 0, n - 1);

    printf("After merge: ");
    for (int i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }

    return 0;
}

