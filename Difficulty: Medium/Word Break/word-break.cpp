class Solution {
  public:
    bool solve(int ind,string &s,unordered_set<string>&st,vector<int>&dp){
        if(ind==s.size()){
            return true;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        for(int j=ind;j<s.size();j++){
            int start=ind;
            int end=j;
            string temp=s.substr(start,end-start+1);
            if(st.find(temp)!=st.end()){
                if(solve(j+1,s,st,dp)) return dp[ind]=true;
            }
        }
        return dp[ind]=false;
    }
    bool wordBreak(string &s, vector<string> &dictionary) {
        // code here
        vector<int>dp(s.size(),-1);
        unordered_set<string>st(dictionary.begin(),dictionary.end());
        return solve(0,s,st,dp);
        
    }
};