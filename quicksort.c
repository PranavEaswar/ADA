#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int partition(int arr[], int high, int low)
{
    int pivot=arr[high];
    int i=low;
    int j=high;

    while(i<j)
    {
        while(arr[i]<=pivot && i<=high-1)
        {
            i++;
        }
        while(arr[j]>pivot && j>=low+1)
        {
            j--;
        }
        if(i<j)
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int t=arr[high];
    arr[high]=arr[j];
    arr[j]=t;

return j;
}
void quicksort(int arr[], int high, int low)
{
    if (low<high)
    {
        int pi=partition(arr, high, low);
        quicksort(arr, low, pi);
        quicksort(arr, pi+1, high);
    }
}


int main()
{
    int n = 100000;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100000;
    }
    clock_t start = clock();
    quicksort(a, 0, n - 1);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort the array of size %d: %f seconds\n", n, time_taken);
    return 0;
}
