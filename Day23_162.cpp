class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // Q. Is Graph Bipartite?
        vector<int> colors(graph.size(), -1);
        for(int node = 0; node < graph.size(); ++node){
            if(colors[node] == -1){
                if(!checkBipartite(node, colors, graph)){
                    return false;
                }
            }
        }
        return true;
    }
    bool checkBipartite(int node, vector<int>& colors, vector<vector<int>>& graph ){
        queue<int> nodeQueue;
        nodeQueue.push(node);
        colors[node] = 0;
        while(!nodeQueue.empty()){
            int currNode = nodeQueue.front();
            nodeQueue.pop();
            for(auto neighbor : graph[currNode]){
                if(colors[neighbor] == -1){
                    colors[neighbor] = !colors[currNode];
                    nodeQueue.push(neighbor);
                }
                else if(colors[neighbor] == colors[currNode]){
                    return false;
                }
            }
        }
        return true;
    }
};