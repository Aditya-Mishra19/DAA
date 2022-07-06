#include<stdio.h> 
# include<time.h>
#define max 500
double tc;
time_t start,end;
void qsort(int [],int,int); 
int partition(int [],int,int); 
int main()
{
	int a[max],i,n;
	printf("Enter the total number of elements: "); 
	scanf("%d",&n);
	printf("Enter the elements to be sorted:\n\n");
	for(i=0;i<n;i++)
	{
		printf("Enter the %d element:",i+1);
		scanf("%d",&a[i]);
		printf("\n");
	}

	printf("\nThe array elements before\n"); 
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
                start=clock();
	qsort(a,0,n-1);
                end=clock();
	printf("\nElements of the array after sorting are:\n"); 
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
               tc=difftime(end,start)/CLOCKS_PER_SEC;
	printf("time efficiency is %lf",tc);
}

void qsort(int a[],int low,int high)
{
	int j; if(low<high)
	{
		j=partition(a,low,high); 
		qsort(a,low,j-1); 
		qsort(a,j+1,high);
	}
}
int partition(int a[], int low,int high)
{
	int pivot,i,j,temp; 
        pivot=a[low]; 
        i=low;
	j=high+1; 
	while(i<=j)
	{
           do
           {
              i++;
           }
           while(pivot>=a[i]);
         
           do 
           {
             j--;
           }    
           while(pivot<a[j]);
         
           if(i<j)
	   {
		temp=a[i]; 
		a[i]=a[j]; 
		a[j]=temp;
	   }
        }
	temp=a[j]; 
	a[j]=a[low]; 
	a[low]=temp;
	
        return j;
		
}

/*Algorithm
Quicksort(A[l...r])
sorts a subarray by quicksort.
Input: Subarray of array A[0,..,n-1] defined
by its left and right indices l and r.
Output: SUbarray A[l,,,r] sorted in nondecreasing order
if l<r
	S<- partition (A[l...r]) // s is split position
	Quicksort(A[l...s-1])
	Quicksort(A[s+1...r])

Algorithm Partition(A[l...r])
// The first element as a pivot
// Input: Subsarray of array A[0..n-1], defined by its left and right indices l and r.
//output:Partition(A[l...r]) with the split position returned as this funcitons value.
p <- A[l]
i <- l; j<-r+1
repeat
	repeat i <- j+1 until A[i] >= p
	repeat j<- j-1 until A[j] <= p
	swaps(A[i], A[j])
until i>=j
swaps(A[i], A[j])
swaps(A[l], A[j])
return j

*/
