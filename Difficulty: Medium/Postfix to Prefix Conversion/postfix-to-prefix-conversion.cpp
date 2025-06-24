// User function Template for C++

class Solution {
  public:
    string postToPre(string s) {
        // Write your code here
         int n=s.size();
        stack<string>stk;
        for(int i=0;i<n;i++){
            if((s[i]<='z' && s[i]>='a')||(s[i]<='Z' && s[i]>='A')||(s[i]<='9' && s[i]>='0')){
                string s2="";
                s2+=s[i];
                stk.push(s2);
            }
            else{
                string t1=stk.top();
                stk.pop();
                string t2=stk.top();
                stk.pop();
                string s3=s[i]+t2+t1;
                stk.push(s3);
            }
        }
        return stk.top();
    }
};