class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int l=0;
        int n=arr.size();
        int r=n-1;
        int ans=0;
        while(l<r){
            int temp=min(arr[l],arr[r])*(r-l);
            ans=max(ans,temp);
            if(arr[l]<arr[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return ans;
    }
};