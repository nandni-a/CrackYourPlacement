//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
         vector<int>dp(arr.size(),0);
        
        for(int i=1;i<arr.size();i++){
            int cost=INT_MAX;
            for(int j=1;j<=k && (i-j)>=0 ;j++){
                cost=min(cost,abs(arr[i]-arr[i-j])+dp[i-j]);
            }
            dp[i]=cost;
        }
        
        return dp[arr.size()-1];
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends