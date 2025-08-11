class Solution {
public:
    int median(vector<vector<int>> &mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        int low = mat[0][0];
        int high = mat[0][n-1];
        for (int i = 0; i < m; i++) {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][n-1]);
        }
        
        int desired = (m * n + 1) / 2;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            int cnt = 0;
            for (int i = 0; i < m; i++) {
                cnt += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            }
            
            if (cnt < desired)
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        return low; 
    }
};
