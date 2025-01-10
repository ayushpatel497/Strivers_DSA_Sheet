class Solution {
public:
    unordered_map<int,string> left, upDia, downDia;
    void addSolution(vector<vector<string>>& board, vector<vector<string>>& ans, int n){
        vector<string> temp;
        for(int i = 0; i < n; ++i){
            string str = "";
            for(int j = 0; j < n; ++j){
                str += board[i][j];
            }
            temp.push_back(str);
        }
        ans.push_back(temp);
    }


    bool isSafe(vector<vector<string>> board, int row, int col, int n){
        if(left[row] == "Q")
            return false;

        if(downDia[row + col] == "Q")
            return false;
        
        if(upDia[n - 1 + col - row] == "Q")
            return false;

        return true;
    }

    void solve(vector<vector<string>> board, int col, int n, vector<vector<string>>& ans){
        if(col == n){
            addSolution(board, ans, n);
            return;
        }

        for(int row = 0; row < n; ++row){
            if(isSafe(board, row, col, n)){
                board[row][col] = "Q";
                left[row] = "Q";
                downDia[row + col] = "Q";
                upDia[n - 1 + col - row] = "Q";
                solve(board, col + 1, n, ans);
                board[row][col] = ".";
                left[row] = ".";
                downDia[row + col] = ".";
                upDia[n - 1 + col - row] = ".";
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        // Q. N-Queens
        vector<vector<string>> ans;
        vector<vector<string>> board(n, vector<string>(n, "."));
        solve(board, 0, n, ans);
        return ans;
    }
};