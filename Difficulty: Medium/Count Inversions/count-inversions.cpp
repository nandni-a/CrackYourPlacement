//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int cnt=0;
    void merge(vector<int>& arr, int l,int mid, int r){
        int i=l;
        int j=mid+1;
        vector<int>ans;
        while(i<=mid && j<=r){
            if(arr[i]<=arr[j]){
                ans.push_back(arr[i]);
                i++;
            }
            else{
                
                ans.push_back(arr[j]);
                cnt+=(mid-i+1);
                j++;
            }
            
        }
        while(i<=mid){
            ans.push_back(arr[i]);
            i++;
        }
        while(j<=r){
            ans.push_back(arr[j]);
            j++;
        }
        for(int i=l;i<=r;i++){
            arr[i]=ans[i-l];
        }
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if(l>=r){
            return;
        }
        int mid= (l + r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        int n=arr.size();
        mergeSort(arr,0,n-1);
        return cnt;
        
        
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends