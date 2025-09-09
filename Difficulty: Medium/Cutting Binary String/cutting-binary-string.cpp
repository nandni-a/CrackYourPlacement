class Solution {
  public:
    unordered_set<string>power;
    void preCompute(int n){
        long long val=1;
        while(val < (1<<n)){
            long long x=val;
            string temp="";
            while(x>0){
                temp= char('0'+ x%2) + temp;
                x/=2;
            }
            power.insert(temp);
            val*=5;
        }
    }
    int solve(int i,string &s,vector<int>&dp){
        if(i==s.size()){
            return 0;
        }    
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=1e9;
        string curr="";
        for(int j=i;j<s.size();j++){
            curr+=s[j];
            if(curr[0]=='0') break;
            if(power.count(curr)){
                int next=solve(j+1,s,dp);
                if(next!=1e9){
                    ans=min(ans,next+1);
                }
            }
        }
        return dp[i]=ans;
        
    }
    int cuts(string s) {
        // code here
        int n=s.size();
        vector<int>dp(n,-1);
        preCompute(n);
        int ans=solve(0,s,dp);
        return (ans>=1e9 ? -1 :ans);
        
    }
};