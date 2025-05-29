class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        // Code here
         if(image[sr][sc] == color){
            return image;
        }
        int old = image[sr][sc];
        image[sr][sc] = color;
        dfs(image,sr,sc,old,color);
        return image;
    }
    void dfs(vector<vector<int>>& image, int sr, int sc, int Old, int New){
        vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};

        int m=image.size();
        int n= image[0].size();
        for(const auto& i:directions){
            int r= sr+i[0];
            int c=sc+i[1];

            if(r<m && r>=0 && c<n && c>=0 && image[r][c]== Old){
                image[r][c]=New;
                dfs(image,r,c,Old,New);
            }
        }
    }
};