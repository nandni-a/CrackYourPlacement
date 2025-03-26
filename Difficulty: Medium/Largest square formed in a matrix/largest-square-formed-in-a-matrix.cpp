//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int solve(vector<vector<int>>& mat , int i,int j,int &maxi,vector<vector<int>>&dp){
        if(i>=mat.size() || j>=mat[0].size()) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int right=solve(mat,i,j+1,maxi,dp);
        int diag=solve(mat,i+1,j+1,maxi,dp);
        int down=solve(mat,i+1,j,maxi,dp);
        
        if(mat[i][j]==1){
            dp[i][j]=1+min(right,min(diag,down));
            maxi=max(maxi,dp[i][j]);
            return dp[i][j];
        }
        else{
            return dp[i][j]=0;
        }
    }
    int maxSquare(vector<vector<int>>& mat) {
        // code here
        int m=mat.size();
        int maxi=0;
        int n=mat[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        solve(mat,0,0,maxi,dp);
        return maxi;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(mat) << "\n"
             << "~\n";
    }
    return 0;
}
// } Driver Code Ends