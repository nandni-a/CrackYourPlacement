class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        vector<pair<int,int>>arr;
        int n=start.size();
        for(int i=0;i<n;i++){
            arr.push_back({finish[i],start[i]});
        }
        sort(arr.begin(),arr.end());
        int cnt=1;
        int last=arr[0].first;
        for(int i=1;i<n;i++){
            if(arr[i].second > last){
                cnt++;
                last=arr[i].first;
            }
        }
        return cnt;
    }
};