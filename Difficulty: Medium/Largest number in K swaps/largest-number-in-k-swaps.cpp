

class Solution {
  public:
    void solve(string &s,int k,int ind,string &ans){
        if(s>ans){
            ans=s;
            
        }
        if(k==0 || ind==s.length()-1){
            return;
        }
        for(int i=ind+1;i<s.length();i++){
            if(s[i]>s[ind]){
                swap(s[i],s[ind]);
                solve(s,k-1,ind+1,ans);
                swap(s[i],s[ind]);
            }
        }
        solve(s,k,ind+1,ans);
    }
    // Function to find the largest number after k swaps.
    string findMaximumNum(string& s, int k) {
        // code here.
        string ans="0";
        solve(s,k,0,ans);
        return ans;
    }
    
};