class Solution {
  public:
    void solve(int ind,int sum,vector<int>&arr,vector<int>&ans){
        if(ind==arr.size()){
            ans.push_back(sum);
            return;
        }
        solve(ind+1,sum+arr[ind],arr,ans);
        solve(ind+1,sum,arr,ans);
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int>ans;
        solve(0,0,arr,ans);
        return ans;
    }
};