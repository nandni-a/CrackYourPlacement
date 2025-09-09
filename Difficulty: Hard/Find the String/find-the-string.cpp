// User function Template for C++
class Solution {
  public:
    string ans;
    string t;
    unordered_set<string>st;
    void solve(int n,int k){
        t=t.substr(1);
        for(int i=k;i>=0;i--){
            t+=to_string(i);
            if(st.find(t)==st.end()){
                ans+=to_string(i);
                st.insert(t);
                return solve(n,k);
            }
            else{
                t.pop_back();
            }
        }
    }
    string findString(int n, int k) {
        // code here
        ans="";
        for(int i=0;i<n;i++){
            ans+='0';
            t+='0';
        }
        st.insert(ans);
        solve(n,k-1);
        return ans;
        
        
    }
};