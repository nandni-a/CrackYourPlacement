class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int l=0;
        int r=0;
        int maxi=0;
        unordered_map<int,int>freq;
        while(r<arr.size()){
            freq[arr[r]]++;
            while(freq.size()>2){
                freq[arr[l]]--;
                
                if(freq[arr[l]]==0) freq.erase(arr[l]);
                l++;
            }
            int len=r-l+1;
            maxi=max(maxi,len);
            r++;
        }
        return maxi;
    }
};