//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // Q. Maximum Sum Combination
        // code here
        priority_queue<pair<int, pair<int, int>>> pq;
        sort(A.begin(), A.end(), greater<int>());
        sort(B.begin(), B.end(), greater<int>());
        
        vector<int> ans;
        
        for(int i = 0; i < N; ++i){
            pq.push({A[i] + B[0], {i, 0}});
        }
        
        while(K--){
            auto it = pq.top();
            pq.pop();
            ans.push_back(it.first);
            pq.push({A[it.second.first] + B[it.second.second + 1],{it.second.first, it.second.second + 1}});
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends