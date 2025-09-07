class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        // Code here.
        int num=0;
        for(auto it:arr){
            num^=it;
        }
        int mask=num & -num;
        int x=0;
        int y=0;
        for(auto it:arr){
            if(it&mask){
                x=x^it;
            }
            else{
                y=y^it;
            }
        }
        vector<int>ans;
        ans.push_back(x);
        ans.push_back(y);
        sort(ans.begin(),ans.end());
        return ans;
    }
};