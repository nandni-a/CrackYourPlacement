class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here

        stack<int> st;
        
        int n=mat.size();
        for (int i = 0; i < n; i++) {
            st.push(i);
        }

 
        while (st.size() > 1) {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();

            if (mat[a][b] == 1) {
                st.push(b);
            } else {
                st.push(a);
            }
        }

        if (st.empty()) return -1;

        int celeb = st.top();

        for (int i = 0; i < n; i++) {
            if (i != celeb && (mat[celeb][i] == 1 || mat[i][celeb] == 0)) {
                return -1;
            }
        }

        return celeb;
    

    }
};