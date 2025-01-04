//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // code here
        // Q. Largest subarray with 0 sum
        int maxLen = 0;
        unordered_map<int, int> um;
        um[0] = -1;
        int sum = 0;
    
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if (um.find(sum) != um.end()) {
                maxLen = max(maxLen, i - um[sum]);
            } else {
                um[sum] = i;
            }
        }
    
        return maxLen;
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
        cout << obj.maxLen(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends