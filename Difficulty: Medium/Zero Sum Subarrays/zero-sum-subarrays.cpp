class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        // code here.
        int res=0;
        int n=arr.size();
        unordered_map<int,int>freq;
        int sum=0;
        freq[0]++;
        for(int i=1;i<=n;i++){
            sum+= arr[i-1];
            freq[sum]++;
            res+= freq[sum]-1;
        }
        return res;
    }
};