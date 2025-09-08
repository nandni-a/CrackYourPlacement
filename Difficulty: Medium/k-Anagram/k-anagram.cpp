class Solution {
  public:
    bool areKAnagrams(string &s1, string &s2, int k) {
        // code here
        if(s1.size()!=s2.size()) return false;
        vector<int>freq(26,0);
        for(char ch:s1) freq[ch-'a']++;
        for(char ch:s2){
            if(freq[ch-'a']>0) freq[ch-'a']--;
            else{
                k--;
            }
        }
        if(k<0) return false;
        return true;
    }
};