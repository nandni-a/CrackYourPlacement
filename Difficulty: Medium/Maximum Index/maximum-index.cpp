class Solution {
  public:
    int maxIndexDiff(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>lMin(n);
        lMin[0]=arr[0];
        for(int i=1;i<n;i++){
            lMin[i]=min(lMin[i-1],arr[i]);
        }
        vector<int>rMax(n);
        rMax[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            rMax[i]=max(rMax[i+1],arr[i]);
        }
        int i=0;
        int j=0;
        int ans=-1;
        while(i<n && j<n){
            if(lMin[i]<=rMax[j]){
                ans=max(ans,j-i);
                j++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};
