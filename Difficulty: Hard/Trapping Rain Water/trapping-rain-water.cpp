class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int l=0;
        int n=arr.size();
        int r=n-1;
        int lMax=0;
        int rMax=0;
        int ans=0;
        while(l<r){
            lMax=max(lMax,arr[l]);
            rMax=max(rMax,arr[r]);
            if(arr[l]<arr[r]){
                
                ans+= lMax-arr[l];
                l++;
            }
            else{
                
                ans+= rMax-arr[r];
                r--;
            }
        }
        return ans;
    }
};