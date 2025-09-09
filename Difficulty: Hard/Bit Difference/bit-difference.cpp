// User function Template for C++

class Solution {
  public:
    int countBits(int N, long long int A[]) {
        // code here
        int MOD=1e9+7;
        long long ans=0;
        for(int i=0;i<32;i++){
            long long cnt1=0;
            for(int j=0;j<N;j++){
                if(A[j]&(1<<i)) cnt1++;
            }
            int cnt0=N-cnt1;
            ans= (ans+ ((cnt1*cnt0)%MOD)*2 %MOD)%MOD;
        }
        return (int)ans;
     
    }
};