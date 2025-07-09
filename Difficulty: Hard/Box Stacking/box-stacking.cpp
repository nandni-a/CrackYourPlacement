class Solution {
  public:
    /*The function takes an array of heights, width and
    length as its 3 arguments where each index i value
    determines the height, width, length of the ith box.
    Here n is the total no of boxes.*/
    int maxHeight(vector<int> &height, vector<int> &width, vector<int> &length) {
        // Your code here
        vector<vector<int>> arr;
        int n=height.size();
        for (int i = 0; i < n; ++i){
            vector<int> per = {height[i], width[i], length[i]};
            sort(per.begin(), per.end());
            
            do {
                arr.push_back(per);
            } while (next_permutation(per.begin(), per.end()));
        }
        
        sort(arr.begin(), arr.end(), [](vector<int> a, vector<int> b) {
          return a[0] * a[1] > b[0] * b[1]; 
        });
        
        n = arr.size();
        vector<int> dp(n);
        
        for (int i = 0; i < n; ++i){
            dp[i] = arr[i][2];
            for (int j = 0; j < i; ++j){
                if (arr[j][0] > arr[i][0] && arr[j][1] > arr[i][1]) {
                    dp[i] = max(dp[i], dp[j] + arr[i][2]);
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
        
    }
};