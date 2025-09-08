class Solution {
  public:
    int n,m;
    
    
    bool isValid(int i,int j){
        if(i>=0 && j>=0 && i<n && j<m){
            return true;
        }
        return false;
    }
    
    bool dfs(string &word,vector<vector<char>>& board,int i,int j,vector<vector<int>>&vis,int ind) {
        if(ind==word.size()) return true;
        vis[i][j]=1;
         int dx[8] = {0, 0, 1, -1, 1, -1, -1, 1};
        int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
        for(int k=0;k<8;k++){
            int nr=i+dx[k];
            int nc=j+dy[k];
            if(isValid(nr,nc) && board[nr][nc]==word[ind] && !vis[nr][nc]){
                if(dfs(word,board,nr,nc,vis,ind+1)) return true;
            }
        }
        vis[i][j]=0;
        return false;
    }
    vector<string> wordBoggle(vector<vector<char> >& board,
                              vector<string>& dictionary) {
        // Code here
        vector<string>ans;
        n=board.size();
        m=board[0].size();
        for(string word:dictionary){
            vector<vector<int>>vis(n,vector<int>(m,0));
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(word[0]==board[i][j]){
                        if(dfs(word,board,i,j,vis,1)){
                            if(ans.size() == 0 || ans.back()!=word) ans.push_back(word);
                        }
                    }
                }
            }
        }
        return ans;
        
    }
};