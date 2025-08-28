class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n=s.size();
        int l=0;
        int ans=-1;
        unordered_map<char,int>freq;
        for(int r=0;r<n;r++){
            freq[s[r]]++;
            if(freq.size()==k){
                ans=max(ans,r-l+1);
            }
            while(freq.size()>k){
                freq[s[l]]--;
                if(freq[s[l]]==0) freq.erase(s[l]);
                l++;
            }
        }
        return ans;
    }
};