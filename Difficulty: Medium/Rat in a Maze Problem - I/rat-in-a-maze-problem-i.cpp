//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool isSafe(int newx , int newy , vector<vector<bool>> &visited,vector<vector<int>> &arr, 
    int n){
        if((newx>=0 && newx<=n-1) && (newy>=0 && newy<=n-1) &&
        visited[newx][newy]!=1 && arr[newx][newy]==1){
            return true;
        }
        return false;
    }
    void solve(int x , int y ,vector<vector<int>> &arr, int n, vector<vector<bool>> &visited,
    string path,vector<string>& ans){
        
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return;
        }
        // d,l,r,u
        // Down
        if(isSafe(x+1,y,visited,arr,n)){
            visited[x][y]=1;
            solve(x+1,y,arr,n,visited,path + "D",ans);
            visited[x][y]=0;
            
        }
        //left
        if(isSafe(x,y-1,visited,arr,n)){
            visited[x][y]=1;
            solve(x,y-1,arr,n,visited,path+ "L",ans);
            visited[x][y]=0;
            
        }
        
        //right
        if(isSafe(x,y+1,visited,arr,n)){
            visited[x][y]=1;
            solve(x,y+1,arr,n,visited,path +"R",ans);
            visited[x][y]=0;
            
        }
        
        //up
        if(isSafe(x-1,y,visited,arr,n)){
            visited[x][y]=1;
            solve(x-1,y,arr,n,visited,path +"U",ans);
            visited[x][y]=0;
            
        }
        
        
        
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // code here
        vector<string>ans;
        if(mat[0][0]==0){
            return ans;
        }
        int n=mat[0].size();
        vector<vector<bool>> visited (n,vector<bool>(n,0));
        string path="";
        solve(0,0,mat,n,visited,path,ans);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends