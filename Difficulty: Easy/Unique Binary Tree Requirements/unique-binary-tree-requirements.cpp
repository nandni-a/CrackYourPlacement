// User function Template for C++

class Solution {
  public:
    bool isPossible(int a, int b) {
        // code here
        if(a==2 && b==2){
            return false;
        }
        if(a==2 || b==2){
            return true;
        }
        return false;
    }
};