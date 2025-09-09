// User function Template for C++

class Solution {
  public:
    int minRepeats(string A, string B) {
        // code here
        string s = A;
        int count = 1;
        while(A.length() < B.length()){
            A += s;
            count++;
        } 
        if(A.find(B) != -1) return count;
        A += s;
        count++;
        if(A.find(B) != -1) return count;
        return -1;
    }
};