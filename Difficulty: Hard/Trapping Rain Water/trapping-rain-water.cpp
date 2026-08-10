class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int l=0;
        int n=arr.size();
        int r=n-1;
        int lmax=0;
        int rmax=0;
        int ans=0;
        while(l<r){
            lmax=max(lmax,arr[l]);
            rmax=max(rmax,arr[r]);
            if(arr[l]<=arr[r]){
                ans+= lmax-arr[l];
                l++;
            }
            else{
                ans+= rmax-arr[r];
                r--;
            }
        }
        return ans;
    }
};