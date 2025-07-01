class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int i=0;
        int j=0;
        int ans=0;
        int cnt=0;
        int n=arr.size();
        while(i<n){
            if(arr[i]<=dep[j]){
                cnt++;
                i++;
            }
            else{
                cnt--;
                j++;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};
