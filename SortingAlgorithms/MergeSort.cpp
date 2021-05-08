#include <bits/stdc++.h>

using namespace std;

void Merge(int arr[], int l, int r, int size)
{
    vector<int> temp(size);
    int mid = (l+r)/2;
    int i=l,j=mid+1,k=l;

    while(i < mid+1 && j < r+1)
    {
        if(arr[i] > arr[j])
            temp[k++] = arr[j++];
        else
            temp[k++] = arr[i++];
    }

    while(i < mid+1)
        temp[k++] = arr[i++];

    while(j < r+1)
        temp[k++] = arr[j++];

    for(int i=l; i<r+1; i++)
        arr[i] = temp[i];
}

void MergeSort(int arr[], int l, int r, int size)
{
    if(l >= r)
        return;
    int mid = (l+r)/2;
    MergeSort(arr, l, mid, size);
    MergeSort(arr, mid+1, r, size);
    Merge(arr, l, r, size);
}