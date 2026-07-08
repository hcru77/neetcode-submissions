class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows, cols;
        map<pair<int, int>, unordered_set<char>> squares;

        for (int r = 0; r < 9; ++r){
            for (int c = 0; c < 9; ++c){
                if (board[r][c] == '.'){
                    continue;
                }

                pair<int, int> sKey = {r / 3, c / 3};
                char val = board[r][c];

                if (rows[r].count(val) ||  cols[c].count(val) || squares[sKey].count(val)){
                    return false;
                }
                rows[r].insert(val);
                cols[c].insert(val);
                squares[sKey].insert(val);
            }
        }
        return true;
    }
};
