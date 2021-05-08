#include <bits/stdc++.h>
#include "Functions.h"
#include "QuickSort.cpp"
#include "ThreeWayQuickSort.cpp"

using namespace std;

int SIZE = 100;

int main(){

    // QuickSort vs ThreeWayQuickSort
    {
        cout << endl;
        cout << "Comparison between QuickSort & ThreeWayQuickSort" << endl;
        cout << endl;
        int size = 100;

        clock_t t;

        vector<int> arr1(size);

        for(int i=0; i<size; i++){
            arr1[i] = 1 + rand() % 10;
            cout << arr1[i] << " ";
        }

        vector<int> arr2(arr1);

        t = clock();
        QuickSort(arr1, 0, size-1);
        t = clock() - t;

        CheckIfSorted(arr1);
        Log(1,t);

        t = clock();
        ThreeWayQuickSort(arr2, 0, size-1);
        t = clock() - t;

        CheckIfSorted(arr2);
        Log(2,t);
    }

}