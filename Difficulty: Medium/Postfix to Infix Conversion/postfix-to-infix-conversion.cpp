// User function Template for C++

class Solution {
  public:
    string postToInfix(string exp) {
        // Write your code here
        int i = 0;
        stack<string> st;
        int n = exp.length();
        while(i<n){
            if(exp[i]>='A' && exp[i]<='Z' || exp[i]>='a' && exp[i]<='z' || exp[i]>='0' && exp[i]<='9'){
                string s = string(1, exp[i]);
                st.push(s);
            }
            else{
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();
                string con = '(' + t2 + exp[i] + t1 + ')';
                st.push(con);
            }
            i++;
        }
        return st.top();
        
    }
};