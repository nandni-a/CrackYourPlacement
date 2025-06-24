// User function Template for C++

class Solution {
  public:
    string preToInfix(string s) {
        // Write your code here
       int n=s.size();
        stack<string>stk;
        for(int i=n-1;i>=0;i--){
            if((s[i]>='a' && s[i]<='z') ||(s[i]>='A' && s[i]<='Z') ||(s[i]>='0' && s[i]<='9')){
                string s2="";
                s2+=s[i];
                stk.push(s2);
            }
            else{
                string t1=stk.top();
                stk.pop();
                string t2=stk.top();
                stk.pop();
                string s3='('+t1+s[i]+t2+')';
                stk.push(s3);
            }
        }
        return stk.top();
    }
};