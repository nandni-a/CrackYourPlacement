class Solution {
  public:
    bool findTriplets(vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            int l=i+1;
            int r=arr.size()-1;
            while(l<r){
                int sum=arr[i]+arr[l]+arr[r];
                if(sum==0){
                    return true;
                }
                else if(sum>0){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        return false;
    }
};