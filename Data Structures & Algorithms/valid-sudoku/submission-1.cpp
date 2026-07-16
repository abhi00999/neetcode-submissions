class Solution {
public:

    bool checkRow(vector<vector<char>>& board, int row){
        set<int> st;
        int cnt = 0;
        for(int i = 0; i<9; i++){
            if(board[row][i]!='.') {st.insert(board[row][i]); cnt++;}
        }
        if(cnt != st.size()) return false;
        return true;
    }
    bool checkColumn(vector<vector<char>>& board, int col){
        set<int> st;
        int cnt = 0;
        for(int i = 0; i<9; i++){
            if(board[i][col]!='.') {st.insert(board[i][col]); cnt++;}
        }
        if(cnt != st.size()) return false;
        return true;
    }
    bool checkSmallBox(vector<vector<char>>& board, int idx, int idy){
        set<int> st;
        int cnt = 0;
        for(int i = idx; i<idx+3; i++){
            for(int j = idy; j<idy+3; j++){
                if(board[i][j]!='.') {st.insert(board[i][j]); cnt++;}
            }
        }
        if(cnt != st.size()) return false;
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            if(checkRow(board, i)) continue;
            else return false; 
        }

        for(int i=0; i<9; i++){
            if(checkColumn(board, i)) continue;
            else return false; 
        }

        vector<vector<int>> cells = {
            {0, 0}, {0, 3}, {0, 6},
            {3, 0}, {3, 3}, {3, 6},
            {6, 0}, {6, 3}, {6, 6}
        };
        for (const auto& cell : cells) {
            int row = cell[0];
            int col = cell[1];

            if(checkSmallBox(board, row, col)) continue;
            else return false;
        }
        return true;
    }
};
