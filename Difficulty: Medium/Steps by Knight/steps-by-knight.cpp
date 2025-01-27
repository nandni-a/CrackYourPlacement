//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    int bfs(vector<int>& KnightPos, vector<int>& TargetPos, int N, vector<vector<int>>& visited) {
        int startx = KnightPos[0] - 1;
        int starty = KnightPos[1] - 1;
        int targetx = TargetPos[0] - 1;
        int targety = TargetPos[1] - 1;

        vector<pair<int, int>> directions = {
            {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
            {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
        };

        queue<pair<pair<int, int>, int>> q;
        q.push({{startx, starty}, 0});
        visited[startx][starty] = 1;

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            int x = curr.first.first;
            int y = curr.first.second;
            int step = curr.second;

            if (x == targetx && y == targety) {
                return step;
            }

            for (auto dir : directions) {
                int newx = x + dir.first;
                int newy = y + dir.second;

                
                if ((newx >= 0 && newx < N && newy >= 0 && newy < N) && !visited[newx][newy]) {
                    visited[newx][newy] = 1;
                    q.push({{newx, newy}, step + 1});
                }
            }
        }

        return -1;  
    }

    int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int N) {
       
        if (KnightPos[0] == TargetPos[0] && KnightPos[1] == TargetPos[1]) {
            return 0;
        }

        vector<vector<int>> visited(N, vector<int>(N, 0));
        return bfs(KnightPos, TargetPos, N, visited);
    }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends