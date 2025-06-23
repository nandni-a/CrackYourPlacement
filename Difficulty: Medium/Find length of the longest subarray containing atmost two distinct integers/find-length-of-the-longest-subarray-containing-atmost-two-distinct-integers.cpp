class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int l=0;
        int r=0;
        int maxi=0;
        int n=arr.size();
        unordered_map<int,int>mapp;
        while(r<n){
            mapp[arr[r]]++;
            if(mapp.size()>2){
                if(mapp.size()>2){
                    mapp[arr[l]]--;
                    if(mapp[arr[l]]==0) mapp.erase(arr[l]);
                    l++;
                }
            }
            if(mapp.size()<=2){
                maxi=max(maxi,r-l+1);
            }
            r++;
            
        }
        return maxi;
    }
};