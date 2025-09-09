class Solution {
  public:
    bool possible(vector<int>& arr, int k, int m,int bouq){
        int cnt=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]<=bouq){
                cnt++;
            }
            else{
                cnt=0;
            }
            if(cnt==k){
                m--;
                cnt=0;
            }
            
        }
        return m<=0;
    }
    int minDaysBloom(vector<int>& arr, int k, int m) {
        // Code here
        int mini=arr[0];
        int maxi=arr[0];
        for(int i:arr){
            mini=min(mini,i);
            maxi=max(maxi,i);
        }
        int l=mini;
        int r=maxi;
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(possible(arr,k,m,mid)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};