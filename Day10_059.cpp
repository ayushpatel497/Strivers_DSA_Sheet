//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void solve(vector<vector<int>> &mat, int i, int j, int n, vector<vector<bool>> vis, string st, vector<string>&ans){
        if(vis[i][j] || mat[i][j] == 0)
            return;
        if(i == n-1 && j == n-1){
            ans.push_back(st);
            return;
        }
        vis[i][j] = true;
        if(i < n - 1)
            solve(mat, i + 1, j, n, vis, st + "D", ans);
        if(j < n - 1)
            solve(mat, i, j + 1, n, vis, st + "R", ans);
        if(i > 0)
            solve(mat, i - 1, j, n, vis, st + "U", ans);
        if(j > 0)
            solve(mat, i, j - 1, n, vis, st + "L", ans);
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        // Q. Rat in a Maze Problem - I
        int n = mat.size();
        vector<string> ans;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        if(mat[0][0] == 1) solve(mat, 0, 0, n, vis, "", ans);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends