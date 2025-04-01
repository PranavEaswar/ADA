#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void merge(int arr[], int left, int right, int mid)
{
    int n1=mid-left+1;
    int n2=right-mid;
    int i,j,k;
    int L[n1], R[n2];
    for (i=0; i<n1; i++)
    {
        L[i]=arr[left+i];
    }
    for (j=0; j<n2; j++)
    {
        R[j]=arr[mid+1+j];
    }
    i=0, j=0, k=left;
    while(i<n1&& j<n2)
    {
        if (L[i]<R[j])
        {
            arr[k++]=L[i++];
        }
        else
        {
            arr[k++]=R[j++];
        }
    }
    while(i<n1)
    {
        arr[k++]=L[i++];
    }
    while(j<n2)
    {
        arr[k++]=R[j++];
    }

}
void mergeSort(int arr[], int left, int right)
{
    if (left<right)
    {
        int mid=left+(right-left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, right, mid);
    }
}



int main()
{
    int n = 100000;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 5500000;
    }
    clock_t start = clock();
    mergeSort(a, 0, n - 1);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort the array of size %d: %f seconds\n", n, time_taken);
    return 0;
}
