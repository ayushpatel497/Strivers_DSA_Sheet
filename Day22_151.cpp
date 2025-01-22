class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // Q. Flood Fill
        int oldColor = image[sr][sc];
        if(oldColor == color) return image;
        vector<pair<int, int>> moves = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> bfsQueue;
        bfsQueue.push({sr, sc});
        while(!bfsQueue.empty()){
            auto [row, col] = bfsQueue.front();
            bfsQueue.pop();
            image[row][col] = color;
            for(auto [r, c] : moves){
                int newRow = row + r;
                int newCol = col + c;
                if(newRow < 0 || newRow >= image.size() || 
                   newCol < 0 || newCol >= image[0].size() || image[newRow][newCol] != oldColor){
                    continue;
                }
                bfsQueue.push({newRow, newCol});
            }
        }
        return image;
    }
};