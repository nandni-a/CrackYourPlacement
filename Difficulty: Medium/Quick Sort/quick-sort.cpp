//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(const vector<int>& arr) {
    for (int num : arr)
        printf("%d ", num);
    printf("\n");
}


// } Driver Code Ends

class Solution {
  public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(vector<int>& arr, int low, int high) {
        // code here
        if(low>=high) return;
        int p=partition(arr,low,high);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }

  public:
    // Function that takes last element as pivot, places the pivot element at
    // its correct position in sorted array, and places all smaller elements
    // to left of pivot and all greater elements to right of pivot.
    int partition(vector<int>& arr, int low, int high) {
        
        // code here
        int pivot=arr[low];
        int cnt=0;
        for(int i=low+1;i<=high;i++){
            if(arr[i]<=pivot){
                cnt++;
            }
        }
        int pIndex=low+cnt;
        swap(arr[low],arr[pIndex]);
        
        int i=low;
        int j=high;
        while(i<pIndex && j>pIndex){
            while(arr[i]<=arr[pIndex] && i < pIndex){
                i++;
            }
            while(arr[j]>arr[pIndex] && j>pIndex){
                j--;
            }
            
            if(i<pIndex && j>pIndex){
                swap(arr[i],arr[j]);
                i++;
                j--;
            }
        }
        return pIndex;
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    scanf("%d", &T);
    getchar(); // to consume newline after T

    while (T--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        ob.quickSort(arr, 0, arr.size() - 1);
        printArray(arr);
    }

    return 0;
}

// } Driver Code Ends