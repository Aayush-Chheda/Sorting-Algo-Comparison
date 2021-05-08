#include<bits/stdc++.h> 
using namespace std; 
const int RUN = 32; 
  
int BinarySearch(int a[], int item, int low, int high)
{
    if (high <= low)
        return (item > a[low]) ? (low + 1) : low;
 
    int mid = (low + high) / 2;

    if (item == a[mid])
        return mid + 1;

    if (item > a[mid])
        return BinarySearch(a, item, mid + 1, high);

    return BinarySearch(a, item, low, mid - 1);
}
 
void BinaryInsertionSort(int a[], int l, int r) 
{ 
    for (int i = l + 1; i <= r; i++) 
    { 
        int temp = a[i]; 
        int j = i - 1; 

        int loc = BinarySearch(a, temp, l, j);

        while (j >= loc) 
        { 
            a[j+1] = a[j]; 
            j--; 
        } 
        a[j+1] = temp; 
    } 
} 
  
void Merge(int a[], int l, int m, int r) 
{ 
    int len1 = m - l + 1, len2 = r - m; 
    int left[len1], right[len2]; 

    for (int i = 0; i < len1; i++) 
        left[i] = a[l + i]; 

    for (int i = 0; i < len2; i++) 
        right[i] = a[m + 1 + i]; 
  
    int i = 0, j = 0, k = l; 
  
    while (i < len1 && j < len2) 
    { 
        if (left[i] <= right[j]) 
        { 
            a[k] = left[i]; 
            i++; 
        } 
        else
        { 
            a[k] = right[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < len1) 
    { 
        a[k] = left[i]; 
        k++; 
        i++; 
    } 
  
    while (j < len2) 
    { 
        a[k] = right[j]; 
        k++; 
        j++; 
    } 
} 
  
void TimSort(int a[], int n) 
{ 
    // Sort individual subarrays of size RUN 
    for (int i = 0; i < n; i+=RUN) 
        BinaryInsertionSort(a, i, min((i+31), (n-1))); 
  
    // start merging from size RUN (or 32). It will merge 
    // to form size 64, then 128, 256 and so on .... 
    for (int size = RUN; size < n; size = 2*size) 
    { 
        // pick starting point of left sub array. We 
        // are going to merge arr[left..left+size-1] 
        // and arr[left+size, left+2*size-1] 
        // After every merge, we increase left by 2*size 
        for (int left = 0; left < n; left += 2*size) 
        { 
            // find ending point of left sub array 
            // mid+1 is starting point of right sub array 
            int mid = left + size - 1; 
            int right = min((left + 2*size - 1), (n-1)); 
  
            // merge sub array arr[left.....mid] & 
            // arr[mid+1....right] 
            Merge(a, left, mid, right); 
        } 
    } 
} 
  
void printArray(double a[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        cout << a[i] << " ";
    cout << endl;
} 
