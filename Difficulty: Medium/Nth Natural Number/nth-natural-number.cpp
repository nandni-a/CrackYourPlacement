// User function Template for C++

class Solution {
  public:
    long long findNth(long long n) {
        // code here.
        long long res=0;
        long long base=1;
        while(n>0){
            res+= (n%9)*base;
            base*=10;
            n/=9;
        }
        return res;
        
    }
};