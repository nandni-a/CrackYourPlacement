

class Solution {
  public:
    long long countSubArrayProductLessThanK(const vector<int>& arr, int n,
                                            long long k) {
        if(k<=1) return 0;
        int l=0;
        long long product=1;
        long long ans=0;
        for(int r=0;r<arr.size();r++){
            product*= arr[r];
            while(product>=k){
                product/=arr[l];
                l++;
            }
            ans+= (r-l+1);
        }
        return ans;
                                
    }
};