class Solution {
public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        int m = mat.size();
        int n = mat[0].size();
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        vector<int> ans;
        
        while (top <= bottom && left <= right) {
            // Left to right
            for (int i = left; i <= right; i++)
                ans.push_back(mat[top][i]);
            top++;
            
            // Top to bottom
            if (top <= bottom) {
                for (int i = top; i <= bottom; i++)
                    ans.push_back(mat[i][right]);
                right--;
            }
            
            // Right to left
            if (top <= bottom) {
                for (int i = right; i >= left; i--)
                    ans.push_back(mat[bottom][i]);
                bottom--;
            }
            
            // Bottom to top
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    ans.push_back(mat[i][left]);
                left++;
            }
        }
        
        return ans;
    }
};
