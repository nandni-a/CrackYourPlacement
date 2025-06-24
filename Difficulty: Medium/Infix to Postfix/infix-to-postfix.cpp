class Solution {
  public:
  int priority(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    if(op == '^') return 3;
    return 0;
}

string infixToPostfix(string& s) {
    int i = 0;
    stack<char> st;
    string ans = "";

    while(i < s.size()) {
        char c = s[i];

        if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            ans += c;
        }
        else if(c == '(') {
            st.push(c);
        }
        else if(c == ')') {
            while(!st.empty() && st.top() != '(') {  
                ans += st.top();
                st.pop();
            }
            if(!st.empty()) st.pop(); 
        }
        else {
            while(!st.empty() && priority(c) <= priority(st.top())) {
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }

        i++;
    }

    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }

    return ans;

    }
};
