//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

    // public:

    // int solve(string& s1, string& s2, int i, int j, int count,vector<vector<int>>&dp) {
    //     if (i == s1.size() || j == s2.size()) {
    //         return count;
    //     }
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    
    //     int ans = count;
    
    //     if (s1[i] == s2[j]) {
    //         dp[i][j] = solve(s1, s2, i + 1, j + 1, count + 1,dp);
    //     }
    
    //     return dp[i][j]=max(ans, max(solve(s1, s2, i + 1, j, count,dp), solve(s1, s2, i, j + 1, count,dp)));
    // }
    
    // int longestCommonSubstr(string& s1, string& s2) {
    //     int m=s1.size();
    //     int n=s2.size();
    //     vector<vector<int>>dp(m,vector<int>(n,-1));
    //     return solve(s1, s2, 0, 0, 0,dp);
    // }
    
//     public int longestCommonSubstr(String s1, String s2)
//     {
        
//                 return A(s1,s2,0,0,0);
                
//     }
//     private int A(String s1,String s2,int n,int m,int length)
//     {
//         if(n==s1.length() || m==s2.length()) return length;
        
//         if(s1.charAt(n)==s2.charAt(m))
//         {
//             length= A(s1,s2,n+1,m+1,length+1);
//         }
        
//         int l= A(s1,s2,n+1,m,0);
//         int r= A(s1,s2,n,m+1,0);
        
//         return Math.max(length,Math.max(l,r));
        
//     }
// // 
// };

// class Solution {
//   public:
//     int maxCount = 0;
//     int solve(string &x,string &y,int n,int m){
//         if(n==0 || m==0)return 0;
        
//         int matchMaxCount = 0;
//         if(x[n-1] == y[m-1]){
//             matchMaxCount = 1 + solve(x,y,n-1,m-1);
//         }
        
//         int notMatched = max(solve(x,y,n-1,m),solve(x,y,n,m-1));
        
//         maxCount = max({maxCount,matchMaxCount,notMatched});
        
        
//         return matchMaxCount;
//     }
//     int longestCommonSubstr(string& s1, string& s2) {
//         int n = s1.size();
//         int m = s2.size();
//         solve(s1,s2,n,m);
//         return maxCount;
//     }
// };

class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        int n = s1.size();
        int m = s2.size();
        int t[n+1][m+1];
        memset(t,0,sizeof(t));
        int maxCount = 0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                    maxCount = max(maxCount,t[i][j]);
                }
                else{
                    t[i][j] = 0;
                }
            }
        }
        return maxCount;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends