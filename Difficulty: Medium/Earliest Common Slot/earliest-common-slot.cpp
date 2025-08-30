class Solution {
  public:
    vector<int> commonSlot(vector<vector<int>> &a, vector<vector<int>> &b, int d) {
        // Code Here
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        int i = 0;
        int j = 0;
        while(i < a.size() && j < b.size()){
            int start = max(a[i][0] , b[j][0]);
            int end = min(a[i][1], b[j][1]);
            
            if(end - start >= d){
                return {start, start + d};
            }
            
            if(a[i][1] < b[j][1]){
                i++;
            }
            else{
                 j++;
            }
        }
        return {};
        
    }
};