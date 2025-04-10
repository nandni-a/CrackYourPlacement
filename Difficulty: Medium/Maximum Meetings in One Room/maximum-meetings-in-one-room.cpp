//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<pair<int,int>>vp;
        int n = S.size();
        for(int i=0;i<N;i++){
            vp.push_back({F[i],i});
        }
        vector<int>ans;
        sort(vp.begin(),vp.end());
        ans.push_back(vp[0].second+1);
        int prev_finish = vp[0].first;
        for(int i=1;i<N;i++){
            if(S[vp[i].second] > prev_finish){
                ans.push_back(vp[i].second+1);
                prev_finish = vp[i].first;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends