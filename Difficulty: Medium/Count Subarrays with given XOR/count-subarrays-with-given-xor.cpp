class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int xr=0;
        int cnt=0;
        unordered_map<int,int>mapp;
        mapp[xr]++;
        for(int i=0;i<arr.size();i++){
            xr=xr^arr[i];
            int x= xr^k;
            cnt+= mapp[x];
            mapp[xr]++;
        }
        return cnt;
    }
};