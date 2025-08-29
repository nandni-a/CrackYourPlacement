
class Solution {
  public:
    vector<vector<int>> kTop(vector<int>& arr, int N, int K) {
        // code here
        set<pair<int,int>>st;
        unordered_map<int,int>freq;
        vector<int>v;
        vector<vector<int>>ans;
        for(int i=0;i<N;i++){
            if(freq[arr[i]]>0) st.erase({-freq[arr[i]],arr[i]});
            freq[arr[i]]++;
            st.insert({-freq[arr[i]],arr[i]});
            int x=K;
            for(auto i:st){
                if(x==0) break;
                v.push_back(i.second);
                x--;
            }
            ans.push_back(v);
            v.clear();
            
        }
        return ans;
    }
};
