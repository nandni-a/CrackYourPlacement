class Solution {
  public:
    int KthMissingElement(vector<int> &arr, int &k) {
        // Complete the function
        int n=arr.size();
        for(int i=0;i<n-1;i++){
            int missing=arr[i+1]-arr[i]-1;
            if(missing>=k){
                return arr[i]+k;
            }
            k-=missing;
        }
        return -1;
    }
};