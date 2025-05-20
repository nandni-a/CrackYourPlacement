class Solution {
  public:
    int func(int mid,int n){
        long long ans=1;
        while(n>0){
            if(n%2==1){
                ans=ans*mid;
                n--;
            }
            else{
                mid=mid*mid;
                n=n/2;
            }
        }
        return ans;
    }
    int nthRoot(int n, int m) {
        // Code here.
        int ans=-1;
        int low=1;
        int high=m;
        while(low<=high){
            int mid=(low+high)/2;
            int midN=func(mid,n);
            if(midN==m){
                return mid;
            }
            else if(midN<m){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return -1;
    }
};