class Solution {
public:
    bool solve(vector<vector<char>>& board, int i, int j, int k,
               string& word, vector<vector<int>>& vis) {

        int m = board.size();
        int n = board[0].size();

        // Entire word matched
        if (k == word.size()) {
            return true;
        }

        // Outside board
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return false;
        }

        // Already used or character doesn't match
        if (vis[i][j] || board[i][j] != word[k]) {
            return false;
        }

        // Mark current cell
        vis[i][j] = 1;

        // Try all 4 directions
        bool ans = solve(board, i + 1, j, k + 1, word, vis) ||
                   solve(board, i - 1, j, k + 1, word, vis) ||
                   solve(board, i, j + 1, k + 1, word, vis) ||
                   solve(board, i, j - 1, k + 1, word, vis);

        // BACKTRACK
        vis[i][j] = 0;

        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (board[i][j] == word[0]) {

                    if (solve(board, i, j, 0, word, vis)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};