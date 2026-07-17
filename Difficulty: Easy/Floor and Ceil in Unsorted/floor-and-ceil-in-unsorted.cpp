class Solution {
  public:
    int upperbound(vector<int>& arr, int x){
        int ans=-1;
        int n=arr.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid] <= x){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
        
    }
    int lowerbound(vector<int>& arr, int x){
        int ans=-1;
        int n=arr.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid] >= x){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
      int floorIdx = upperbound(arr, x);
        int ceilIdx = lowerbound(arr, x);
    
        int floor = (floorIdx == -1) ? -1 : arr[floorIdx];
        int ceil = (ceilIdx == -1) ? -1 : arr[ceilIdx];
        return {floor, ceil};
        
    }
};