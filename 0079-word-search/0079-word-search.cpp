class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    bool func(int i, int j, int k, vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        if (k == word.size()) {
            return true;
        }
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '\0') {
            return false;
        }
        if (board[i][j] != word[k]) {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '\0'; 

        for (int x = 0; x < 4; x++) {
            int new_i = i + dr[x];
            int new_j = j + dc[x];
            if (func(new_i, new_j, k + 1, board, word)) {
                return true;
            }
        }

        board[i][j] = temp; 
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (func(i, j, 0, board, word)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
