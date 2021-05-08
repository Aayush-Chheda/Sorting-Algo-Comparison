#pragma once

#include<bits/stdc++.h>

using namespace std;

void printArray(int arr[], int size)
{
 	for (int i = 0; i < size; i++) 
 		cout << arr[i] << " "; 
 	cout << endl; 
}

void CheckIfSorted(vector<int> a)
{   
    bool flag = true;
    for(int i=1; i<a.size(); i++)
        if(a[i] < a[i-1]){
            flag = false;
            break;
        }
    if(flag)
        cout << "Array is Sorted";
    else
        cout << "Array is not Sorted";
    cout << endl;
}

void Log(int i, clock_t t){
    cout << "Time required to sort arr" << i << ": " << t*1000 << "ms" << endl;
}
