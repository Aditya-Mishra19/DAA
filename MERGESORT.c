#include<stdio.h> 
#include<time.h>
#define MAX 50
void mergeSort(int arr[],int low,int mid,int high); 
void partition(int arr[],int low,int high);
double tc;
time_t start,end;
void main()
{
	int a[MAX],i,n;
	printf("Enter the total number of elements: "); 
	scanf("%d",&n);
	printf("Enter the elements to be sorted:\n\n");
	for(i=0;i<n;i++)
	{
		printf("Enter the %d element:",i+1);
		scanf("%d",&a[i]);
		printf("\n");
	}
            start=clock();
	partition(a,0,n-1);
            end=clock();
	printf("After merge sorting elements are: "); 
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
            tc=difftime(end,start)/CLOCKS_PER_SEC;
	printf("time efficiency is %lf",tc);
}
void partition(int arr[],int low,int high)
{
	int mid; 
	if(low<high)
	{
		mid=(low+high)/2; 
		partition(arr,low,mid); 
		partition(arr,mid+1,high); 
		mergeSort(arr,low,mid,high);
	}
}
void mergeSort(int arr[],int low,int mid,int high)
{ 
	int i,m,k,l,temp[MAX];
	l=low; i=low; m=mid+1;
        while((l<=mid)&&(m<=high))
        { 
		if(arr[l]<=arr[m])
                {
			temp[i]=arr[l]; 
			l++;
		}
		else
		{
			temp[i]=arr[m]; 
			m++;
		}
			i++;
	}

        while(l<=mid)
        {
           temp[i]=arr[l];
           i++;
           l++;
        }
        while(m<=high)
        {
           temp[i]=arr[m];
           i++;
           m++;
        }

	for(k=low;k<=high;k++)
	{ 
		arr[k]=temp[k];
	}
}
/* ALgorithm
algo mergersort(A[0,..,n-1])
//Sorts array A[0,..n-1] by recursive merge sort.
//Input: AN array A[0,..n-1]
//Output: Array A[0...n-1] sorted in non decreasing order.
if n>1
copy A[0...|_ n/2 _|-1] to B[0....|_ n/2 _|-1]
copy A[|_n/2_|..n-1] to c[0...|_n/2_|-1]
mergeSort(C(n/2)-1)
merge(B,C,A) // see below

Algorithm merge(B[0...p-1], C[0..q-1], A[0...p+q-1])
//Merges tow sorted arrays into one sorted array
//InPut- Array B[0...p-1], C[0..q-1] botht sorted
//Output: Sorted Array  A[0...p+q-1] of the elements of B and C.

i<-0; j <- 0; k<-0;
while i<p and j<q do
	if B[i] <= C[j]
		A[k] <- B[i]; i<-i+1
	else A[k]<- C[j]; j<-j+1
	k <- k+1
if i=p
	copy C[j..q-1] to A[k....p+q-1]
else copy B[j..p-1] to A[k....p+q-1]
*/