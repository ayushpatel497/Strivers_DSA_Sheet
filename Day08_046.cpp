//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    static bool cmp(vector<int> &a, vector<int> &b){
        double r1 = (double) a[0] / (double) a[1];
        double r2 = (double) b[0] / (double) b[1];
        return r1 > r2;
    }
    
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // Your code here
        // Q. Fractional Knapsack
        int n = val.size();
        vector<vector<int>> item(n, vector<int>(2,0));
        for(int i = 0; i < n; ++i){
            item[i][0] = val[i];
            item[i][1] = wt[i];
        }
        
        sort(item.begin(), item.end(), cmp);
        
        double totalVal = 0;
        int currW = 0;
        for(int i = 0; i < n; ++i){
            if(currW + item[i][1] <= capacity){
                currW += item[i][1];
                totalVal += item[i][0];
            }
            else{
                double remain = capacity - currW;
                totalVal += (item[i][0] / (double) item[i][1]) * (double) remain;
                break;
            }
        }
        return totalVal;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends