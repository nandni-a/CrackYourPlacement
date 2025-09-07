class Solution {
  public:
    int maxIndexDiff(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>lMin(n);
        vector<int>rMax(n);
        lMin[0]=arr[0];
        for(int i=1;i<n;i++){
            lMin[i]=min(arr[i],lMin[i-1]);
        }
        rMax[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            rMax[i]=max(arr[i],rMax[i+1]);
        }
        int i=0,j=0,ans=0;
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
