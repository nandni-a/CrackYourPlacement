//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool solve(int index,int n,vector<int>& arr,int target,vector<vector<int>>&dp){
        if(index >= n){
            return false;
        }
        if(target <0) return false;
        if(target==0) return true;
        if(dp[index][target]!=-1) return dp[index][target];
        
        bool incl=solve(index+1,n,arr,target-arr[index],dp);
        bool excl = solve(index+1,n,arr,target-0,dp);
        
        return dp[index][target]=incl or excl;
        
    }
    bool equalPartition(vector<int>& arr) {
        // code here
        int n=arr.size();
        int total=0;
        for(int i=0;i<n;i++){
            total+=arr[i];
        }
        if(total & 1) return false;
        int target=total/2;
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(0,n,arr,target,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends