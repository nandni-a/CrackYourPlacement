//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    long long solve(int n,vector<vector<int>> keypad,int i,int j,vector<vector<vector<long long>>>&dp){
        if(i<0 || i>=keypad.size() || j<0 || j>=keypad[0].size() || keypad[i][j]==-1){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(dp[n][i][j]!=-1){
            return dp[n][i][j];
        }
        long long a=solve(n-1,keypad,i,j,dp);
        long long b=solve(n-1,keypad,i-1,j,dp);
        long long c=solve(n-1,keypad,i+1,j,dp);
        long long d=solve(n-1,keypad,i,j-1,dp);
        long long e=solve(n-1,keypad,i,j+1,dp);
        
        return dp[n][i][j]=a+b+c+d+e;
        
        
        
    }
    long long getCount(int n) {
        vector<vector<int>> keypad={{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
        long long ans=0;
        vector<vector<vector<long long>>>dp(n+1,vector<vector<long long>>(5,vector<long long>(4,-1)));
        for(int i=0;i<keypad.size();i++){
            for(int j=0;j<keypad[0].size();j++){
                if(keypad[i][j]!=-1){
                    ans+=solve(n,keypad,i,j,dp);
                }
            }
        }
        return ans;
        // Your code goes here
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends