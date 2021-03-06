// C++ implementation of Radix Sort 
#include<bits/stdc++.h> 

using namespace std; 

// A utility function to get maximum value in arr[] 
int getMax(int arr[], int n) { 
    return *max_element(arr, arr+n);
} 
    
// A function to do counting sort of arr[] according to 
// the digit represented by exp. 
void countSort(int arr[], int n, int exp) { 
	int output[n]; // output array 
	int i, count[10] = {0}; 

	// Store count of occurrences in count[] 
	for (i = 0; i < n; i++) 
		count[(arr[i]/exp)%10]++; 

	// Change count[i] so that count[i] now contains actual 
	// position of this digit in output[] 
	for (i = 1; i < 10; i++) 
		count[i] += count[i - 1]; 

	// Build the output array 
	for (i = n - 1; i >= 0; i--) { 
		output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
		count[(arr[i]/exp)%10]--; 
	} 

	// Copy the output array to arr[], so that arr[] now 
	// contains sorted numbers according to current digit 
	for (i = 0; i < n; i++) 
		arr[i] = output[i]; 
} 

// The main function to that sorts arr[] of size n using 
// Radix Sort 
void RadixSort(int arr[], int n) { 
	// Find the maximum number to know number of digits 
	int m = getMax(arr, n); 

	// Do counting sort for every digit. Note that instead 
	// of passing digit number, exp is passed. exp is 10^i 
	// where i is current digit number 
	for (int exp = 1; m/exp > 0; exp *= 10) 
		countSort(arr, n, exp); 
} 

// A utility function to print an array 
void print(int arr[], int n) { 
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 
} 

// Driver program to test above functions 
int main() { 
	int arr[] = {170, 45, 75, 90, 802, 24, 2, 66}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	RadixSort(arr, n); 
	print(arr, n); 
	return 0; 
} 

// int main() 
// {  
//     static constexpr size_t INPUT_SIZE = 1000;
//     static constexpr int MIN_KEY = 0;
//     static constexpr int MAX_KEY = 1;

//     // Generate some random uniformly distributed data
//     random_device rd;
//     mt19937 g(rd());
//     uniform_real_distribution<> distribution(MIN_KEY, MAX_KEY);

//     double a[INPUT_SIZE] = {};
//     for(int i=0; i<INPUT_SIZE; i++)
//         a[i] = distribution(g);

//     // printf("Given Array is\n"); 
//     // printArray(a, INPUT_SIZE); 

  
//     // printf("After Sorting Array is\n"); 
//     // printArray(a, INPUT_SIZE); 
//     //CheckIfSorted(a, INPUT_SIZE);
//     return 0; 
// }