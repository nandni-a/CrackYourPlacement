class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        // Code here
        int cnt1=0;
        int cnt2=0;
        int el1=INT_MIN;
        int el2=INT_MIN;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(cnt1==0 && arr[i]!=el2){
                cnt1=1;
                el1=arr[i];
            }
            else if(cnt2==0 && arr[i]!=el1){
                cnt2=1;
                el2=arr[i];
            }
            else if(arr[i]==el1){
                cnt1++;
            }
            else if(arr[i]==el2){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(el1==arr[i]) cnt1++;
            else if(el2==arr[i]) cnt2++;
        }
        int val=n/3;
        vector<int>ans;
        if(cnt1>val) ans.push_back(el1);
        if(cnt2>val) ans.push_back(el2);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
    
};