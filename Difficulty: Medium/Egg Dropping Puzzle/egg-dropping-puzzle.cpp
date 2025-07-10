class Solution {
  public:

    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int solve(int n,int k,vector<vector<int>>&dp){
        if(k==0 || k==1){
            return k;
        }
        if(n==1){
            return k;
        }
        if(dp[n][k]!=-1){
            return dp[n][k];
        }
        int start=1;
        int end=k;
        int ans=1e9;
        while(start<=end){
            int mid= start+ (end-start)/2;
            int breaked=solve(n-1,mid-1,dp);
            int safe=solve(n,k-mid,dp);
            int temp= 1+ max(breaked,safe);
            if(breaked > safe){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
            ans=min(ans,temp);
        }
        return dp[n][k]=ans;
    }
    int eggDrop(int n, int k) {
        // code here
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return solve(n,k,dp);
    }
};