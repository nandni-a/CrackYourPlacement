//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int f(int n){
        int sum =0;
        for(int i =1 ;i*i<=n; i++){
            if(n%i==0){
                sum+=i;
                if((n/i)!= i) sum+=(n/i);
            }
        }
        return sum;
    }
    long long sumOfDivisors(long long n) {
        // Code here
        int grand_sum=0;
        for(int i =1; i<=n;i++){
            grand_sum += f(i);
        }
        return grand_sum;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        int ans = ob.sumOfDivisors(N);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends