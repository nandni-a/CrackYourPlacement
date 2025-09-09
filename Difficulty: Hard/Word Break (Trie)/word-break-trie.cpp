// User function template for C++

class Solution {
  public:
    // A : given string to search
    // B : vector of available strings
    bool wordBreakRec(string &A, unordered_set<string> &dict) {
        if(A.empty()) return true;
    
        for(int i=1; i<=A.size(); i++){
            string prefix = A.substr(0, i);
            string suffix = A.substr(i);
            if(dict.find(prefix) != dict.end() && wordBreakRec(suffix, dict))
                return true;
        }
    
        return false;
    }

    int wordBreak(string A, vector<string> &B) {
        // code here
        unordered_set<string> dict(B.begin(), B.end());
        return wordBreakRec(A,dict);
    }
};