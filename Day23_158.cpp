class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Q. Course Schedule
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        for(int courses = 0; courses < prerequisites.size(); ++courses){
            adj[prerequisites[courses][1]].push_back(prerequisites[courses][0]);
            indegree[prerequisites[courses][0]] += 1;
        }

        queue<int> nodeQueue;
        for(int node = 0; node < indegree.size(); ++node){
            if(indegree[node] == 0){
                nodeQueue.push(node);
            }
        }
        
        int count = 0;
        while(!nodeQueue.empty()){
            int currNode = nodeQueue.front();
            nodeQueue.pop();
            count += 1;
            for(auto neighbor : adj[currNode]){
                indegree[neighbor] -= 1;
                if(indegree[neighbor] == 0){
                    nodeQueue.push(neighbor);
                }
            }
        }
        
        return count == numCourses;
    }
};