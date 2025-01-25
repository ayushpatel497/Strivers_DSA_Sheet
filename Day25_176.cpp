//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    int recursion(int start, int end, vector<int> &arr){
        if(start == end){
            return 0;
        }
        int minimum = INT_MAX;
        for(int index = start; index < end; ++index){
            int answer = recursion(start, index, arr) + recursion(index + 1, end, arr) + arr[start - 1] * arr[index] * arr[end];
            minimum = min(answer, minimum);
        }
        return minimum;
    }
    
    int memoization(int start, int end, vector<int> &arr, vector<vector<int>>& dp){
        if(start == end){
            return 0;
        }
        if(dp[start][end] != -1){
            return dp[start][end];
        }
        
        int minimum = INT_MAX;
        for(int index = start; index < end; ++index){
            int answer = memoization(start, index, arr, dp) + memoization(index + 1, end, arr, dp) + arr[start - 1] * arr[index] * arr[end];
            minimum = min(answer, minimum);
        }
        return dp[start][end] = minimum;
    }
    
    int tabulation(vector<int> &arr, int arrSize){
        vector<vector<int>> dp(arrSize + 1, vector<int>(arrSize + 1, 0));
        
        for(int length = 2; length < arrSize; ++length){
            for(int start = 1; start <= arrSize - length; ++start){
                int end = start + length - 1;
                int minimum = INT_MAX;
                for(int index = start; index < end; ++index){
                    int answer = dp[start][index] + dp[index + 1][end] + arr[start - 1] * arr[index] * arr[end];
                    minimum = min(answer, minimum);
                }
                dp[start][end] = minimum;
            }
        }
        return dp[1][arrSize - 1];
    }
    
  public:
    int matrixMultiplication(vector<int> &arr) {
        // Q. Matrix Chain Multiplication
        // code here
        int arrSize = arr.size();
        return recursion(1, arrSize - 1, arr);
        vector<vector<int>> dp(arrSize, vector<int>(arrSize, -1));
        return memoization(1, arrSize - 1, arr, dp);
        return tabulation(arr, arrSize);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl << "~\n";
    }

    return 0;
}

// } Driver Code Ends