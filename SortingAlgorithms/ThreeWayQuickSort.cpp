#include<bits/stdc++.h>
using namespace std;

pair<int,int> partition3(vector<int> &arr, int l, int r) {

  int i,j;
  if (r - l <= 1) {
     if (arr[r] < arr[l])
        swap(arr[r], arr[l]);
     i = l;
     j = r;
     return make_pair(i, j);
  }
  int mid = l;
  int pivot = arr[r];
  while (mid <= r) {
    if (arr[mid]<pivot)
        swap(arr[l++], arr[mid++]);
    else if (arr[mid]==pivot)
        mid++;
    else if (arr[mid] > pivot)
        swap(arr[mid], arr[r--]);
  }
  i = l-1;
  j = mid;

  return make_pair(i,j);
}

void ThreeWayQuickSort(vector<int> &arr, int l, int r) 
{
  if( r <= l)
    return;
  // random number between l and r
  int n = l + rand() % (r - l);
  // swap with element at l so that our normal partion function works
  swap(arr[l], arr[n]);

  pair<int, int> p1 = partition3(arr, l, r);

  ThreeWayQuickSort(arr, l, p1.first);
  ThreeWayQuickSort(arr, p1.second, r);

}
