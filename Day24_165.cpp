//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Q. Dijkstra Algorithm
        // Code here
        vector<int> dist(adj.size(), INT_MAX);
        set<pair<int, int>> nodeSet;
        dist[src] = 0;
        nodeSet.insert({0, src});
        while(!nodeSet.empty()){
            auto currSmall = *(nodeSet.begin());
            int currNode = currSmall.second;
            int currDist = currSmall.first;
            
            nodeSet.erase(nodeSet.begin());
            for(auto neighbor : adj[currNode]){
                if(currDist + neighbor.second < dist[neighbor.first]){
                    auto record = nodeSet.find({dist[neighbor.first], neighbor.first});
                    if(record != nodeSet.end()){
                        nodeSet.erase(record);
                    }
                    
                    dist[neighbor.first] = currDist + neighbor.second;
                    nodeSet.insert({dist[neighbor.first], neighbor.first});
                }
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends