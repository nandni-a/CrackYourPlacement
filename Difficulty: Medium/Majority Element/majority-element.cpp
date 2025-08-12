class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        if(n==1) return arr[0];
        int candidate=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(cnt==0){
                candidate=arr[i];
            }
            if(candidate==arr[i]){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        if(cnt==0) return -1;
        int ans=0;
        for(int i=0;i<n;i++){
            if(arr[i]==candidate) ans++;
            
        }
        if(ans>=(n/2)+1) return candidate;
        return -1;
    }
};