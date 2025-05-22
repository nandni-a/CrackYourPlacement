// User function template for C++
class Solution {
  public:
    int lowerBound(vector<int>& arr, int x) {
        int start = 0, end = arr.size() - 1;
        int ans = arr.size(); 
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] >= x) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
}
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n=arr.size();
        int m=arr[0].size();
        int cnt_max=-1;
        int index=-1;
        for(int i=0;i<n;i++){
            int cnt_ones=m-lowerBound(arr[i],1);
            if(cnt_ones>cnt_max){
                cnt_max=cnt_ones;
                index=i;
            }
        }
        return index;
        
    }
};