//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int minimumDays(int S, int N, int M) {
        // code here
        
         if(M > N) return -1;
        if((S >= 7) && (((N-M)*6) < M)) return -1;
        
        int toatalFood = S*M;
        
        if(toatalFood%N == 0){
            return (toatalFood/N);
        }
        else{
            return ((toatalFood/N)+1);
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int S, N, M;
        cin >> S >> N >> M;

        Solution ob;
        cout << ob.minimumDays(S, N, M) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends