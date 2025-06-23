// User function template for C++

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // your code here
        int l=0;
        int r=0;
        int maxi=0;
        int n=s.size();
        unordered_map<char,int>mapp;
        while(r<n){
            mapp[s[r]]++;
            if(mapp.size()>k){
                if(mapp.size()>k){
                    mapp[s[l]]--;
                    if(mapp[s[l]]==0) mapp.erase(s[l]);
                    l++;
                }
            }
            if(mapp.size()==k){
                maxi=max(maxi,r-l+1);
            }
            r++;
            
        }
        if(maxi==0) return -1;
        return maxi;
    }
};