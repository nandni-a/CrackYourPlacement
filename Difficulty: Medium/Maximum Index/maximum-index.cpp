class Solution {
  public:
    int maxIndexDiff(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>lmin(n);
        vector<int>rmax(n);
        lmin[0]=arr[0];
        rmax[n-1]=arr[n-1];
        for(int i=1;i<n;i++){
            lmin[i]=min(lmin[i-1],arr[i]);
        }
        for(int i=n-2;i>=0;i--){
            rmax[i]=max(rmax[i+1],arr[i]);
        }
        int i=0;
        int j=0;
        int ans=0;
        while(i<n && j<n){
            if(lmin[i]<=rmax[j]){
                ans = max(ans,j-i);
                j++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};