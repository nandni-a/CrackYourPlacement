//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &profit) {
        // code here
        vector<pair<int, int>>v;
        int n=id.size();
        for(int i=0; i<n; i++){
            v.push_back({profit[i], i});
        }
        sort(v.rbegin(), v.rend());
        
        vector<int>t(n, -1);
        int tot_prof=0, cnt=0;
        for(int i=0; i<n; i++){
            for(int j=deadline[v[i].second]-1; j>=0; j--){
                if(t[j]==-1){
                    t[j]=id[v[i].second];
                    tot_prof+=v[i].first;
                    cnt++;
                    break;
                }
            }
        }
        return {cnt, tot_prof};
    }
};



//{ Driver Code Starts.
//            Driver program to test methods
int main() {
    int t;
    // testcases
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> jobIDs, deadlines, profits;
        string temp;
        getline(cin, temp);
        istringstream ss1(temp);
        int x;
        while (ss1 >> x)
            jobIDs.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss3(temp);
        while (ss3 >> x)
            profits.push_back(x);

        int n = jobIDs.size();

        Solution obj;
        vector<int> ans = obj.JobSequencing(jobIDs, deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends