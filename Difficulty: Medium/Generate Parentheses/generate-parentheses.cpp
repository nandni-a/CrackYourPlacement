// User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution {
  public:
    void solve(int open,int close,string temp,vector<string>&ans){
        if(open==0 && close==0){
            ans.push_back(temp);
            return;
        }
        if(open>0){
            solve(open-1,close,temp+"(",ans);
        }
        if(close>open){
            solve(open,close-1,temp+")",ans);
        }
    }
    vector<string> generateParentheses(int n) {
        // code here
        vector<string>ans;
        if(n%2!=0){
            return ans;
        }
        string temp="";
        
        solve(n/2,n/2,temp,ans);
        return ans;
    }
};