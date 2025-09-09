
class Solution {
  public:
    void solve(int i,string&p,vector<string>&ans,string&s){
        if(i>=s.size()){
            ans.push_back(p);
            return;
        }
        if(s[i]=='?'){
            p.push_back('0');
            solve(i+1,p,ans,s);
            p.pop_back();
            
            p.push_back('1');
            solve(i+1,p,ans,s);
            p.pop_back();
        }
        
        else{
            p.push_back(s[i]);
            solve(i+1,p,ans,s);
            p.pop_back();
        } 
    }
    vector<string> generate_binary_string(string s) {
        // Code here
        vector<string> ans;
        string p;
        solve(0,p,ans,s);
        return ans;
    }
};