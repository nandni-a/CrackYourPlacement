class Solution {
  public:
    bool minPages(int mid,vector<int>&arr,int k){
        int stu=1;
        int curr=0;
        for(int it:arr){
            if(curr+it > mid){
                stu++;
                curr=it;
                if(stu>k) return false;
            }
            else{
                curr+=it;
            }
            
        }
        return true;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int sum=0;
        int maxi=0;
        if(k>arr.size()) return -1;
        for(int i:arr) {
            maxi=max(maxi,i);
            sum+= i;
        }
        int ans=sum;
        int l=maxi;
        int r=sum;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(minPages(mid,arr,k)){
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