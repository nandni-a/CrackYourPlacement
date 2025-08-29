class Solution {
  public:
    int closest3Sum(vector<int> &arr, int target) {
        // code here
        int ans=0;
        sort(arr.begin(),arr.end());
        int minDiff=INT_MAX;
        int n=arr.size();
        for(int i=0;i<n-2;i++){
            int l=i+1;
            int r=n-1;
            while(l<r){
                int curr=arr[i]+arr[l]+arr[r];
                if(abs(curr-target)<minDiff){
                    ans=curr;
                    minDiff=abs(curr-target);
                }
                else if(abs(curr-target)==minDiff){
                    ans=max(ans,curr);
                }
                if(curr>target){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        return ans;
    }
};