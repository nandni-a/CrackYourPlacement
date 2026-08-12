class Solution {
  public:
    int isValid(string &s) {
        // code here
        int parts=0;
        int n=s.length();
        int i=0;
        while(i<n){
            if(s[i]=='.'){
                return false;
            }
            if(parts==4){
                return false;
            }
            if(s[i]=='0'){
                i++;
                if(i<n && s[i]!='.'){
                    return false;
                }
                parts++;
                if(i<n){
                    i++;
                }
                continue;
            }
            int num=0;
            int digits=0;
            while(i<n && s[i]!='.'){
                if(s[i]<'0' || s[i]>'9') return false;
                num=num*10 + (s[i]-'0');
                digits++;
                if(digits>3 || num>255) return false;
                i++;
            }
            parts++;
            if(i<n){
                i++;
            }
        }
        return parts==4;
    }
};