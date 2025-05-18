//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:

    int findFloor(vector<int>& arr, int x) {
        // Your code here
        int start=0;
         int end = arr.size()-1;
         int ans=-1;
         while(start<=end){
         int mid=start+(end-start)/2;
          if(arr[mid]<=x){
              ans=mid;
              start=mid+1;
          }
          else{
              end=mid-1;
          }
      }
     return ans;
    }
};



//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int x = stoi(ks);
        Solution ob;
        int ans = ob.findFloor(arr, x);

        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends