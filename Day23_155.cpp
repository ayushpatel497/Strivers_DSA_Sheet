#include <bits/stdc++.h>
using namespace std;

class Solution {
private: 
    bool detect(int node, vector<int> adj, vector<bool>& visited) {
        visited[node] = true;
        queue<pair<int,int>> nodeQueue; 
        nodeQueue.push({src, -1});
        while(!nodeQueue.empty()) {
            int node = nodeQueue.front().first; 
            int parent = nodeQueue.front().second; 
            nodeQueue.pop(); 
            for(auto neighbor: adj[node]) {
                if(!visited[neighbor]) {
                    visited[neighbor] = true; 
                    nodeQueue.push({neighbor, node}); 
                }
                else if(parent != neighbor) {
                    return true; 
                }
            }
        }
        return false; 
    }
public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj) {
        // Q. Detect Cycle in an Undirected Graph (using BFS)
        vector<bool> visited(V, 0);
        for(int node = 0; node < V; ++node) {
            if(!visited[node]) {
                if(detect(node, adj, visited)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    // V = 4, E = 2
    vector<int> adj = {{}, {2}, {1, 3}, {2}};
    Solution obj;
    bool ans = obj.isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}