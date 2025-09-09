// User function Template for C++
class Solution {
  public:
    vector<int> maximumToys(int N, vector<int> A, int Q, vector<vector<int>> Queries) {
        // code here
        vector<pair<int,int>> toys; // {cost, index}
        for (int i = 0; i < N; i++) {
            toys.push_back({A[i], i});
        }
        
        // Sort by cost
        sort(toys.begin(), toys.end());
        
        // Prefix sum of costs
        vector<long long> prefix(N+1, 0);
        for (int i = 0; i < N; i++) {
            prefix[i+1] = prefix[i] + toys[i].first;
        }
        
        vector<int> ans;
        
        for (auto &query : Queries) {
            int C = query[0];
            int K = query[1];
            unordered_set<int> broken;
            for (int i = 2; i < 2 + K; i++) {
                broken.insert(query[i] - 1);
            }
            
            // Binary search: how many toys can we buy ignoring broken
            int l = 0, r = N, maxToys = 0;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (prefix[mid] <= C) {
                    maxToys = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            
            // Adjust for broken toys among chosen ones
            int count = maxToys;
            long long money = prefix[maxToys];
            
            for (int i = 0; i < maxToys; i++) {
                if (broken.count(toys[i].second)) {
                    count--;
                    money -= toys[i].first;
                }
            }
            
            // Try to buy next cheapest toys after skipping broken
            for (int i = maxToys; i < N; i++) {
                if (!broken.count(toys[i].second) && money + toys[i].first <= C) {
                    money += toys[i].first;
                    count++;
                }
            }
            
            ans.push_back(count);
        }
        
        return ans;
    }
};