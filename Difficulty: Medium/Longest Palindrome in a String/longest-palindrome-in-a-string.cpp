class Solution {
  public:
    string longestPalindrome(string &s) {
        // code here
        string ans="";
        int maxLen=0;
        int n=s.length();
        int l=0;
        int r=0;
        for(int i=0;i<n;i++){
            l=i;
            r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                if(maxLen< r-l+1){
                    maxLen=max(maxLen,r-l+1);
                    ans=s.substr(l,r-l+1);
                }
                l--;
                r++;
            }
            
            l=i;
            r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                if(maxLen< r-l+1){
                    maxLen=max(maxLen,r-l+1);
                    ans=s.substr(l,r-l+1);
                }
                l--;
                r++;
            }
            
            
        }
        return ans;
    }
};