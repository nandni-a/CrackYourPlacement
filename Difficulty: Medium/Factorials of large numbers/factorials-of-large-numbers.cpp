// User function template for C++

class Solution {
  public:
    vector<int> factorial(int n) {
        // code here
        vector<int>ans;
        ans.push_back(1);
        for(int i=2;i<=n;i++){
            int carry=0;
            for(int j=0;j<ans.size();j++){
                int pro=ans[j]*i+carry;
                ans[j]=pro%10;
                carry=pro/10;
            }
            while(carry>0){
                ans.push_back(carry%10);
                carry/=10;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};