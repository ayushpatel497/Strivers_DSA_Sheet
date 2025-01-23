class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // Q. Is Graph Bipartite?
        vector<int> colors(graph.size(), -1);
        for(int node = 0; node < graph.size(); ++node){
            if(colors[node] == -1){
                colors[node] = 0;
                if(!checkBipartite(node, colors, graph)){
                    return false;
                }
            }
        }
        return true;
    }
    bool checkBipartite(int node, vector<int>& colors, vector<vector<int>>& graph ){
        for(auto neighbor : graph[node]){
            if(colors[neighbor] == -1){
                colors[neighbor] = !colors[node];
                if(!checkBipartite(neighbor, colors, graph)){
                    return false;
                }
            }
            else if(colors[neighbor] == colors[node]){
                return false;
            }
        }
        return true;
    }
};