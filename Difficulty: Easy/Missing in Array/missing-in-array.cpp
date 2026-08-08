class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        long long n=arr.size();
        long long e=n+1;
        long long s = (e*(e+1))/2;
        long long sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        return (s-sum);
        
    }
};