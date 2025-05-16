//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        vector<int>hash(arr.size()+1,0);
        vector<int>ans(2);
        for(int i=0;i<arr.size();i++){
            hash[arr[i]]++;
        }
        for(int i=1;i<=arr.size();i++){
            if(hash[i]==2){
                ans[0]=i;
            }
            if(hash[i]==0){
                ans[1]=i;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends