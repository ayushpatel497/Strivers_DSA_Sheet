class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Q. Rotate Image
        int n = matrix.size();
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < n; ++i){
            int s = 0, e = n - 1;
            while(s < e){
                swap(matrix[i][s++], matrix[i][e--]);
            }
        }
    }
};