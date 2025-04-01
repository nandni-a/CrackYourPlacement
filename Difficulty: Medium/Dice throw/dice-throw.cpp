//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int solve(int dice,int face,int target,vector<vector<int>>&dp){
      
      if(target <0 ) return 0;
      if(dice==0 && target!=0) return 0;
      if(dice!=0 && target==0) return 0;
      if(dice==0 && target==0) return 1;
      if(dp[dice][target]!=-1) return dp[dice][target];
      int ans=0;
      
      for(int i=1;i<=face;i++){
          ans = ans+ solve(dice-1,face,target-i,dp);
      }
      return dp[dice][target]=ans;
      
  }
    int noOfWays(int m, int n, int x) {
        // code here
        vector<vector<int>>dp(n+1,vector<int>(x+1,-1));
        return solve(n,m,x,dp);
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        int m, n, x;
        cin >> m >> n >> x;

        Solution ob;
        cout << ob.noOfWays(m, n, x) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends