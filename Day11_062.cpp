//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int upperBound(vector<int> &arr, int x, int n) {
        int start = 0, end = n - 1;
        int ans = n;
    
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] > x) {
                ans = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return ans;
    }
    
    int countSmallEqual(vector<vector<int>> &matrix, int m, int n, int x) {
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            cnt += upperBound(matrix[i], x, n);
        }
        return cnt;
    }
    
    int median(vector<vector<int>> &matrix) {
        // code here
        // Q. Median in a row-wise sorted Matrix
        int m = matrix.size();
        int n = matrix[0].size();
        int start = INT_MAX, end = INT_MIN;
    
        //point start and end to right elements:
        for (int i = 0; i < m; i++) {
            start = min(start, matrix[i][0]);
            end = max(end, matrix[i][n - 1]);
        }
    
        int req = (n * m) / 2;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int smallEqual = countSmallEqual(matrix, m, n, mid);
            if (smallEqual <= req) start = mid + 1;
            else end = mid - 1;
        }
        return start;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        int ans = -1;
        ans = obj.median(matrix);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends