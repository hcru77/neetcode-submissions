class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();

        vector<int> dX {1, 0, -1, 0};
        vector<int> dY {0, 1, 0, -1};

        int res = 0;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (grid[i][j] == 1) {
                    // start bfs here, mark seen islands as 0
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = -1;
                    while (!q.empty()) {
                        auto p = q.front();
                        int cRow = p.first, cCol = p.second;
                        q.pop();
                        
                        int childs = 0;
                        for (int k = 0; k < 4; ++k) {
                            int nRow = cRow + dX[k];
                            int nCol = cCol + dY[k];
                            
                            if (nRow >= 0 && nRow < N && nCol >= 0 && nCol < M && 
                                grid[nRow][nCol] != 0) {
                                if (grid[nRow][nCol] == 1) {
                                    q.push({nRow, nCol});
                                    grid[nRow][nCol] = -1;
                                }
                                childs++;
                            }
                        }
                        res += (4 - childs);
                    }
                    
                }
            }
        }
        return res;
    }
};