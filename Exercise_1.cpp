/*

Time Complexity : O(logN)
Space Complexity : O(1)

*/



#include <iostream>
  
// A recursive binary search function. It returns 
// location of x in given array arr[l..r] is present, 
// otherwise -1 
int binarySearch(int arr[], int l, int r, int x) 
{   
    
    //Your Code here
    if (l<=r)
    {
        int m{};
        m = (l+r)/2;
        if(arr[m] == x)
            return m;
        else if (arr[m]>x)
            return binarySearch(arr,l,m-1,x);
        else if (arr[m]<x)
            return binarySearch(arr,m+1,r,x);
    }
    return -1;
    
} 
  
int main(void) 
{ 
    int arr[] = { 2, 3, 4, 10, 40 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int x = 10; 
    int result = binarySearch(arr, 0, n - 1, x); 
    (result == -1) ? printf("Element is not present in array") 
                   : printf("Element is present at index %d", 
                            result); 
    return 0;
}