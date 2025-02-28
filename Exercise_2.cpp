/*
// Time Complexity : The time complexity varies with the case
for unsorted array where the pivot is in the middle for each recurssion ,
it is O(logN)
For worst case, the sorted array, the time complexity is O(N^2)

// Space Complexity : O(1) 
It doesnt require any extra space apart from storing the recursive function calls

// Did this code successfully run on Leetcode :
// Any problem you faced while coding this :


// Your code here along with comments explaining your approach 
*/


#include<iostream>
using namespace std;  
  
// A utility function to swap two elements  
void swap(int* a, int* b)  
{  
    //Your Code here 
    int temp{*a};
    *a = *b;
    *b = temp;
}  
  
/* This function takes last element as pivot, places  
the pivot element at its correct position in sorted  
array, and places all smaller (smaller than pivot)  
to left of pivot and all greater elements to right  
of pivot */
int partition (int arr[], int low, int high)  
{  
    //Your Code here
    int pivot {arr[high]};
    int i{low-1};
    for(int j{low};j<high;j++)
    {
        if(arr[j]<pivot)
        {
            ++i;
            swap(&arr[j],&arr[i]);
        }
    }
    swap(&arr[++i],&arr[high]);
    return i;

}  
  
/* The main function that implements QuickSort  
arr[] --> Array to be sorted,  
low --> Starting index,  
high --> Ending index */
void quickSort(int arr[], int low, int high)  
{  
    //Your Code here 
    if(low<high)
    {
        int p{partition(arr,low,high)};
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }
}  
  
/* Function to print an array */
void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  
  
// Driver Code 
int main()  
{  
    int arr[] = {10, 7, 8, 9, 1, 5};  
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Given array "<<endl;
    printArray(arr,n);
    quickSort(arr, 0, n - 1);  
    cout << "Sorted array: \n";  
    printArray(arr, n);  
    return 0;  
}  