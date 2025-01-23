//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Q BFS of graph
        // Code here
        int nodeCount = adj.size();
        vector<int> answer;
        vector<bool> visited(nodeCount, false);
        queue<int> nodeQueue;
        visited[0] = true;
        nodeQueue.push(0);
        while(!nodeQueue.empty()){
            int node = nodeQueue.front();
            nodeQueue.pop();
            answer.push_back(node);
            for(auto neighbor : adj[node]){
                if(!visited[neighbor]){
                    visited[neighbor] = true;
                    nodeQueue.push(neighbor);
                }
            }
        }
        return answer;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        // Now using vector of vectors instead of array of vectors
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); // For undirected graph, add both u->v and v->u
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends