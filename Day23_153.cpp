//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Q. DFS of Graph
        // Code here
        int nodeCount = adj.size();
        vector<int> answer;
        vector<bool> visited(nodeCount, false);
        
        for(int node = 0; node < nodeCount; ++node){
            if(!visited[node]){
                fillAnswer(node, adj, answer, visited);
            }
        }
        
        return answer;
    }
    
    void fillAnswer(int node, vector<vector<int>> adj, vector<int>& answer, vector<bool>& visited){
        visited[node] = true;
        answer.push_back(node);
        for(auto neighbor : adj[node]){
            if(!visited[neighbor]){
                fillAnswer(neighbor, adj, answer, visited);
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends