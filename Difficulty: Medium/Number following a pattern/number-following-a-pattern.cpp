class Solution {
  public:
    string printMinNumberForPattern(string s) {
        // code here
        stack<int>st;
        int num=1;
        string ans="";
        int n=s.length();
        for(int i=0;i<n;i++){
            st.push(num);
            num++;
            if(s[i]=='I'){
                while(!st.empty()){
                    ans+=to_string(st.top());
                    st.pop();
                    
                }
            }
        }
        st.push(num);
        while(!st.empty()){
            ans+=to_string(st.top());
            st.pop();
        }
        return ans;
    }
};
