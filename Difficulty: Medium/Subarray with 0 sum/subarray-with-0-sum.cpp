class Solution {
  public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(vector<int>& arr) {
        // Your code here
         int n=arr.size();
        vector<int>prefix(n,0);
        prefix[0]=arr[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+arr[i];
        }
        unordered_map<int,int>mapp;
        for(int i=0;i<n;i++){
            if(prefix[i]==0) return true;
            if(mapp.count(prefix[i])) return true;
            mapp[prefix[i]]++;
        }
        return false;
    }
};