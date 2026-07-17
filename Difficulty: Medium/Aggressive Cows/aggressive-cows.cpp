class Solution {
  public:
    bool canPlace(vector<int> &arr, int k,int mid){
        int cnt=1;
        int last=arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i]-last >= mid){
                cnt++;
                last=arr[i];
            }
            if(cnt>=k) return true;
        }
        return false;
    }
    int aggressiveCows(vector<int> &arr, int k) {
        // code here
        int low=0;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int high = arr[n-1]-arr[0]; 
        while(low<=high)
           { int mid=(low+high)/2;
            if(canPlace(arr,k,mid)){
                low=mid+1;
                
                
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
};