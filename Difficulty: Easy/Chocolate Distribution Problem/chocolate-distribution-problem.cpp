class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        sort(a.begin(),a.end());
        
        int mini = INT_MAX; 
       int i = 0; 
       int j = m-1; 
       while(j < a.size()){
           int diff = a[j]- a[i]; 
           mini = min(mini , diff); 
           i++, j++; 
       }
       return mini;
    }
};