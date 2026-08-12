class Solution {
  public:
    int countTriangles(vector<int>& arr) {
        // code here
        int ans=0;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        for(int k=n-1;k>=2;k--){
            int i=0;
            int j=k-1;
            while(i<j){
                int sum=arr[i]+arr[j];
                if(sum > arr[k]){
                    ans+= (j-i);
                    j--;
                }
                else{
                    i++;
                }
            }
        }
        return ans;
    }
};
