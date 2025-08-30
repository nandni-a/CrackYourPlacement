class Solution {
  public:
    vector<vector<int>> findIntersection(vector<vector<int>> a, vector<vector<int>> b) {
        int i=0;
        int j=0;
        int n=a.size();
        int m=b.size();
        vector<vector<int>>ans;
        while(i<n && j<m){
            int start=max(a[i][0],b[j][0]);
            int end=min(a[i][1],b[j][1]);
            if(start<=end) ans.push_back({start,end});
            
            if(a[i][1]<b[j][1]) i++;
            else j++;
        }
        return ans;
    
    }
};