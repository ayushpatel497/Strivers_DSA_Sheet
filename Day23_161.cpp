class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int numIslands(vector<vector<char>>& grid) {
        // Q. Number of Islands
        int rowSize = grid.size();
        int colSize = grid[0].size();
        int islandCount = 0;
        for(int row = 0; row < rowSize; ++row){
            for(int col = 0; col < colSize; ++col){
                if(grid[row][col] == '1'){
                    exploreIsland(grid, row, col, rowSize, colSize);
                    islandCount += 1;
                }
            }
        }
        return islandCount;
    }
    void exploreIsland(vector<vector<char>>& grid, int row, int col, int rowSize, int colSize){
        grid[row][col] = '0';
        for(auto [r, c] : directions){
            int newRow = r + row;
            int newCol = c + col;
            if(isValid(newRow, newCol, rowSize, colSize) && grid[newRow][newCol] == '1')
                exploreIsland(grid, newRow, newCol, rowSize, colSize);
        }
    }

    bool isValid(int row, int col, int rowSize, int colSize){
        return row >= 0 && col >= 0 && row < rowSize && col < colSize;
    }
};