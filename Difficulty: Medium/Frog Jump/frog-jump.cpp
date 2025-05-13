//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int>& height,int index,vector<int>&dp){
        if(index<=0){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int stair1= solve(height,index-1,dp) + abs(height[index]-height[index-1]);
        int stair2=INT_MAX;
        if(index>1) stair2= solve(height,index-2,dp) + abs(height[index]-height[index-2]);
        return dp[index]=min(stair1,stair2);
        
        
    }
    int minCost(vector<int>& height) {
        // Code here
        int cost=0;
        vector<int>dp(height.size(),-1);
        return solve(height,height.size()-1,dp);
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends