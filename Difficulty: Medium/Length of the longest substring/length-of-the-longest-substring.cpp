class Solution {
  public:
    int longestUniqueSubstring(string &s) {
        // code
        unordered_map<char,int>freq;
        int l=0;
        int len=0;
        for(int r=0;r<s.length();r++){
            
            while(freq.find(s[r])!=freq.end()){
                freq[s[l]]--;
                if(freq[s[l]]==0) freq.erase(s[l]);
                l++;
            }
            freq[s[r]]++;
            len=max(len,r-l+1);
            
            
            
        }
        return len;
    }
};