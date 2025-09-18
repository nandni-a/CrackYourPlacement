class Solution {
  public:
    int towerOfHanoi(int n, int from, int to, int aux) {
        // code here
        if(n==0 || n==1) return n;
        int ans=0;
        ans+=towerOfHanoi(n-1,from,aux,to);
        ans++;
        ans+=towerOfHanoi(n-1,aux,to,from);
        return ans;
    }
};