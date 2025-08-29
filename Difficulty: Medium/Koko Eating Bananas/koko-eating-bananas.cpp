class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int low=1;
        int high=INT_MIN;
        for(int i:arr){
            high=max(high,i);
        }
        while(low<high){
            int mid=low + (high-low)/2;
            if(canEat(mid,arr,k)){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
    bool canEat(int speed,vector<int>&arr,int k){
        long long hours=0;
        for(auto it:arr){
            hours+= (it+speed-1) / speed;
            if(hours>k) return false;
        }
        return hours<=k;
    }
};