class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<pair<int,int>> directions={{-1,-1},{-1,0},{0,-1},{0,1},{1,1},{1,0},{1,-1},{-1,1}};
        vector<pair<int,int>> toOne,toZero;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int live=0;
                for(int k=0;k<8;k++){
                    int row =i+directions[k].first;
                    int col=j+directions[k].second;
                    if(row>=0 && col>=0 && row<m && col<n && board[row][col]==1){
                        live++;
                    }
                }
                if(board[i][j]==1){
                    if(live < 2 || live >3){
                        toZero.push_back({i,j});
                    }
                }
                else{
                    if(live ==3){
                        toOne.push_back({i,j});
                    }
                }
            }
        }
        for(auto x:toZero){
            board[x.first][x.second]=0;
        }
        for(auto x:toOne){
            board[x.first][x.second]=1;
        }
        
    }
};