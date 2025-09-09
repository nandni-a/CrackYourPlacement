// User function Template for C++

class Solution {
  public:
    string findAndReplace(string s, int q, int index[], string sources[],
                          string targets[]) {
        // code here
        unordered_map<int,pair<string,string>>mapp;
        for(int i=0;i<q;i++){
            mapp[index[i]]={sources[i],targets[i]};
        }
        string ans="";
        int i=0;
        int n=s.length();
        while(i<n){
            if(mapp.count(i)){
                string src=mapp[i].first;
                string tgt=mapp[i].second;
                if(s.substr(i,src.length())==src){
                    ans+=tgt;
                    i+=src.size();
                }
                else{
                    ans+=s[i];
                    i++;
                }
            }
            else{
                ans+=s[i];
                i++;
            }
        }
        return ans;
    }
};