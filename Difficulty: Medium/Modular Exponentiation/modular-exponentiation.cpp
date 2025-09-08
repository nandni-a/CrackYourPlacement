class Solution {
  public:
    int powMod(int x, int n, int M) {
        // code here
        if(n==1){
            return x;
        }
        
        long long int ans = powMod(x, n/2, M) % M;
        ans = (ans * ans) % M;
        
        if(n%2!=0){
            ans=(ans*x) % M;
        }
        return ans % M;
    }
};