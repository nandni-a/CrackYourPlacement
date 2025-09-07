class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        // Your code goes here
        int sum=0;
        int l=0;
        int len=INT_MAX;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            while(sum>x){
                len=min(len,i-l+1);
                sum-=arr[l];
                l++;
            }
            
            
        }
        return len==INT_MAX ? 0 :len;
    }
};