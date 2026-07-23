class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int N = heights.size();
        int M = heights[0].size();

        vector<vector<bool>> pac(N, vector<bool>(M, false));
        vector<vector<bool>> atl(N, vector<bool>(M, false));

        // right, down, left, up
        vector<int> dX {1, 0, -1, 0};
        vector<int> dY {0, 1, 0, -1};


        auto dfs = [&](auto &&self, int r, int c, vector<vector<bool>>& ocean) -> void
        {
            ocean[r][c] = true;
            for (int i = 0; i < 4; ++i) {
                int nRow = r + dY[i], nCol = c + dX[i];
                if (nRow >= 0 && nRow < N && nCol >= 0 && nCol < M &&
                ocean[nRow][nCol] == false && heights[r][c] <= heights[nRow][nCol]) {
                    self(self, nRow, nCol, ocean);
                }
            }
        };

        for (int r = 0; r < N; ++r) {
            if (r == 0){
                for (int c = 0; c < M; ++c) {
                    dfs(dfs, r, c, pac);
                }
            }
            else {
                dfs(dfs, r, 0, pac);
            }
        }

        for (int r = 0; r < N; ++r) {
            if (r == N - 1){
                for (int c = 0; c < M; ++c) {
                    dfs(dfs, r, c, atl);
                }
            }
            else {
                dfs(dfs, r, M - 1, atl);
            }
        }

        vector<vector<int>> res{};
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (pac[i][j] == true && atl[i][j] == true) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};
