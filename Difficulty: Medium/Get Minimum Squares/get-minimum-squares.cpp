//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int solve(int n,vector<int> &dp){
        if(n==0){
            return 0;
        }
        // if(n<0){
        //     return 0;
        // }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans=n;
        for(int i=1;i*i<=n;i++){
            ans=min(ans,solve(n-(i*i),dp)+1);
        }
        dp[n]=ans;
        return dp[n];
    }
    int MinSquares(int n) {
        // Code here
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.MinSquares(n);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends