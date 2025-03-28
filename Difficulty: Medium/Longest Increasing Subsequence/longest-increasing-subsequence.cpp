//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int>& arr , int n,int curr, int prev,vector<vector<int>>&dp){
        if(curr==n) return 0;
        if(dp[curr][prev+1] !=-1) return dp[curr][prev+1];
        int include=0;
        if(prev==-1 || arr[curr]>arr[prev]){
            include=1+ solve(arr,n,curr+1,curr,dp);
        }
        int exclude= 0+ solve(arr,n,curr+1,prev,dp);
        return dp[curr][prev+1]=max(include,exclude);
    }
    int lis(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(arr,n,0,-1,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends