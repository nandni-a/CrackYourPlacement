class Solution {
  public:
    int possible(vector<int>& arr, int k,int mid){
        int cnt=1;
        int sum=0;
        for(int i=0;i<arr.size();i++){
            if(sum+arr[i] <=mid){
                sum+=arr[i];
            }
            else{
                cnt++;
                sum=arr[i];
            }
        }
        return cnt;
    }
    int splitArray(vector<int>& arr, int k) {
        // code here
        int maxi=arr[0];
        int sum=0;
        for(int i=0;i<arr.size();i++){
            maxi=max(maxi,arr[i]);
            sum+=arr[i];
        }
        int low=maxi;
        int high=sum;
        int ans=0;
        while(low<=high){
            int mid=low + (high-low)/2;
            if(possible(arr,k,mid)>k){
                low=mid+1;
            }
            else{
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};