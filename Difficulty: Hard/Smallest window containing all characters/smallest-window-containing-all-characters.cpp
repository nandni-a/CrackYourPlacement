class Solution {
  public:
    string smallestWindow(string &s, string &p) {
        // code here
        if(p.length()> s.length()) return "";
        int n=s.length();
        int m=p.length();
        int start=-1;
        int len=INT_MAX;
        vector<int>freqP(26,0);
        vector<int>freqS(26,0);
        int uniqueP=0;
        int match=0;
        int l=0;
        for(char ch:p){
            freqP[ch-'a']++;
            if(freqP[ch-'a']==1) uniqueP++;
        }
        for(int r=0;r<n;r++){
            freqS[s[r]-'a']++;
            if(freqS[s[r]-'a'] == freqP[s[r]-'a']) match++;
            
            if(match == uniqueP){
                while(freqS[s[l]-'a']> freqP[s[l]-'a']){
                    freqS[s[l]-'a']--;
                    l++;
                }
                if(len > r-l+1){
                    start=l;
                    len=r-l+1;
                }
            }
        }
        if(start==-1) return "";
        return s.substr(start,len);
        
    }
};