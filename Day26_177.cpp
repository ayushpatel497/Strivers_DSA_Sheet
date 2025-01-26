class Solution {
public:
    int recursion(vector<vector<int>>& grid, int row, int col, int rowSize, int colSize){
        if(row == rowSize - 1 && col == colSize - 1){
            return grid[row][col];
        }
        if(row >= rowSize || col >= colSize){
            return 1e9;
        }
        int right = grid[row][col] + recursion(grid, row, col + 1, rowSize, colSize);
        int down = grid[row][col] + recursion(grid, row + 1, col, rowSize, colSize);

        return min(right, down);
    }

    int memoization(vector<vector<int>>& grid, int row, int col, int rowSize, int colSize, vector<vector<int>>& dp){
        if(row == rowSize - 1 && col == colSize - 1){
            return grid[row][col];
        }
        if(row >= rowSize || col >= colSize){
            return 1e9;
        }
        if(dp[row][col] != -1){
            return dp[row][col];
        }
        int right = grid[row][col] + memoization(grid, row, col + 1, rowSize, colSize, dp);
        int down = grid[row][col] + memoization(grid, row + 1, col, rowSize, colSize, dp);

        return dp[row][col] = min(right, down);
    }

    int tabulation(vector<vector<int>>& grid, int rowSize, int colSize){
        vector<vector<int>> dp(rowSize + 1, vector<int>(colSize + 1, 0));
        for(int row = 0; row < rowSize; ++row){
            dp[row][colSize] = 1e9;
        }
        for(int col = 0; col < colSize; ++col){
            dp[rowSize][col] = 1e9;
        }
        for(int row = rowSize - 1; row >= 0; --row){
            for(int col = colSize - 1; col >= 0; --col){
                if(row == rowSize - 1 && col == colSize - 1){
                    dp[row][col] = grid[row][col];
                    continue;
                }
                int right = grid[row][col] + dp[row][col + 1];
                int down = grid[row][col] + dp[row + 1][col];
                dp[row][col] = min(right, down);
            }
        }
        return dp[0][0];
    }

    int spaceOptimized(vector<vector<int>>& grid, int rowSize, int colSize){
        vector<int> curr(colSize + 1, 0);
        vector<int> next(colSize + 1, 0);
        for(int col = 0; col < colSize; ++col){
            next[col] = 1e9;
        }
        for(int row = rowSize - 1; row >= 0; --row){
            curr[colSize] = 1e9;
            for(int col = colSize - 1; col >= 0; --col){
                if(row == rowSize - 1 && col == colSize - 1){
                    curr[col] = grid[row][col];
                    continue;
                }
                int right = grid[row][col] + curr[col + 1];
                int down = grid[row][col] + next[col];
                curr[col] = min(right, down);
            }
            next = curr;
        }
        return next[0];
    }

    int minPathSum(vector<vector<int>>& grid) {
        // Q. Minimum Path Sum
        int rowSize = grid.size(), colSize = grid[0].size();
        return recursion(grid, 0, 0, rowSize, colSize);
        vector<vector<int>> dp(rowSize, vector<int>(colSize, -1));
        return memoization(grid, 0, 0, rowSize, colSize, dp);
        return tabulation(grid, rowSize, colSize);
        return spaceOptimized(grid, rowSize, colSize);
    }
};