// link - https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/
// Author - Riya Singh

#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int low, int high, int key){
    if(high<low) return -1;
    
        int mid = (high + low)/2;
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid]<key){
            binarySearch(arr, n, mid+1, high, key);
        }
        else{
            binarySearch(arr, n, low, mid-1, key);
        }
    
    
}

int findPivot(int arr[], int n, int low, int high){
    
    if(low>high) return -1;
    int mid = (high + low)/2;
    if(mid<high && arr[mid]>arr[mid+1]) return mid;
    if(mid>low && arr[mid]<arr[mid-1]) return mid-1;
    if(arr[low]>arr[mid]) return findPivot(arr, n, low, mid-1);
    return findPivot(arr, n, mid+1, high);
}

int binarySearchModified(int arr[], int n, int low, int high, int key){
    
    if(low>high) return -1;
    int pivot = findPivot(arr, n, low, high-1);
    if(arr[pivot]==key) return pivot;
    if(arr[low]<key && arr[pivot]>key) return binarySearch(arr, n, low, pivot-1, key);
    return binarySearch(arr, n, pivot+1, high, key);
}




int main()
{
    
    int arr1[] = {5, 6, 7, 8, 9, 10, 1, 2, 3 };
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int key = 3;
    
    //cout << "Index of the element is : "<< binarySearch(arr1, n, 0, n-1, key);
    cout<<binarySearchModified(arr1, n, 0, n-1, key );
    return 0;
}