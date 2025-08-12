class Solution {
  public:
    int first(vector<int>& arr, int x){
        int l=0;
        int n=arr.size();
        int r=n-1;
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(arr[mid]==x){
                ans=mid;
                r=mid-1;
            }
            else if(arr[mid]>x){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
    int last(vector<int>& arr, int x){
        int l=0;
        int n=arr.size();
        int r=n-1;
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(arr[mid]==x){
                ans=mid;
                l=mid+1;
            }
            else if(arr[mid]>x){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
    vector<int> find(vector<int>& arr, int x) {
        // code here
        return {first(arr,x),last(arr,x)};
    }
};