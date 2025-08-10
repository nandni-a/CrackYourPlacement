// User function template for C++

class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        // code here
        int n=arr.size();
        int l=0;
        int r=n-1;
        sort(arr.begin(),arr.end());
        
        set<pair<int,int>>st;
        while(l<r){
            if(arr[l]+arr[r]==0){
                st.insert({arr[l],arr[r]});
                l++;
                r--;
            }
            else if(arr[l]+arr[r]>0){
                r--;
            }
            else{
                l++;
            }
        }
        vector<vector<int>> ans;
        for (auto &p : st) {
            ans.push_back({p.first, p.second});
        }
        return ans;
    }
};