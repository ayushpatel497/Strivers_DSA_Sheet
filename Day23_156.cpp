#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(int node, int parent, vector<bool>& visited, vector<int> adj) {
        visited[node] = true;
        for(auto neighbor: adj[node]) {
            if(!visited[neighbor]) {
                if(dfs(neighbor, node, visited, adj)){
                    return true;
                }
            }
            else if(neighbor != parent) return true; 
        }
        return false; 
    }
public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj) {
        // Q. Detect Cycle in an Undirected Graph (using DFS)
        vector<int> visited(V, 0);
        for(int node = 0; node < V; ++node) {
            if(!visited[node]) {
                if(dfs(node, -1, visited, adj)){ 
                    return true;
                } 
            }
        }
        return false; 
    }
};

int main() {
    
    // V = 4, E = 2
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    Solution obj;
    bool ans = obj.isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}