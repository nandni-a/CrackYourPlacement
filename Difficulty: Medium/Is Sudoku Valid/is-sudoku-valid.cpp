class Solution {
  public:
   bool isValid(vector<vector<int>> mat, int r, int c){
        for(int i=0;i<9;i++){
            
            if( mat[r][i] == mat[r][c] && i!=c){
                return false;
            }
            if( mat[i][c] == mat[r][c] && i!=r){
                return false;
            }
            if(mat[3*(r/3)+i/3][3*(c/3)+i%3] == mat[r][c] && (3*(r/3)+i/3)!=r && (3*(c/3)+i%3)!=c){
                return false;
            }
        }
        return true;
    }
    bool isValid(vector<vector<int>>& mat) {
        // code here
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(mat[i][j]!=0){
                    if(!isValid(mat,i,j)){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};