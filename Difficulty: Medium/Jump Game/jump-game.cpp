// User function Template for C++

class Solution {
  public:
    // Function to check if we can reach the last index from 0th index.
    bool canReach(vector<int> &arr) {
        // code here
        int i=0;
        while(i<arr.size()){
            int jump=arr[i];
            if(jump==0) return false;
            i+=jump;
        }
        return true;
    }
};