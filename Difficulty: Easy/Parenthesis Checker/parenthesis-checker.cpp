
class Solution {
  public:
    bool isBalanced(string& k) {
        if(k.length()<=1) return false;
        // code here
        stack<char>st;
        for(char ch:k){
            if(ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
            }
            else if(st.empty()) return false;
            else {
                if(ch==')'){
                    if(st.top()!='(') return false;
                    else st.pop();
                }
                else if(ch=='}'){
                    if(st.top()!='{') return false;
                    else st.pop();
                }
                else{
                    if(st.top()!='[') return false;
                    else st.pop();
                }
                
            }
        }
        if(st.empty()) return true;
        return false;
        
    }
};