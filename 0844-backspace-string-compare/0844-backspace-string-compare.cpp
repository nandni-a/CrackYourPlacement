// class Solution {
// public:
//     bool backspaceCompare(string s, string t) {
//         stack<char>st1;
//         stack<char>st2;
        
//         for(int i=0;i<s.size();i++){
//             if(s[i]=='#' && !st1.empty()){
//                 st1.pop();
                
//             }
//             else{
//                 st1.push(s[i]);
//             }
//         }
//         for(int i=0;i<t.size();i++){
//             if(t[i]=='#' && !st2.empty()){
//                 st2.pop();
                
//             }
//             else{
//                 st2.push(t[i]);
//             }
//         }
        
//         while(!st1.empty() && !st2.empty()){
//             if(st1.top()==st2.top()){
//                 st1.pop();
//                 st2.pop();
//             }
            
            
            
            
//         }
//         if( st1.empty() && st2.empty()){
//             return true;
//         }
//         return false;
        
//         return st1==st2;
        
//     }
// };

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1, st2;
        
        auto buildStack = [](string& str) {
            stack<char> st;
            for (char ch : str) {
                if (ch == '#' && !st.empty()) st.pop();
                else if (ch != '#') st.push(ch);
            }
            return st;
        };
        
        st1 = buildStack(s);
        st2 = buildStack(t);
        
        return st1 == st2;
    }
};
