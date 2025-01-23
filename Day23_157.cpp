class Solution {
public:
    bool dfsCall(int course, vector<vector<int>> adj, vector<bool>& visited, vector<bool>& dfsVisited){
        visited[course] = true;
        dfsVisited[course] = true;
        for(auto neighbor : adj[course]){
            if(dfsVisited[neighbor]){
                return true;
            }
            else if(!visited[neighbor]){
                if(dfsCall(neighbor, adj, visited, dfsVisited)){
                    return true;
                }
            }
        }
        dfsVisited[course] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Q. Course Schedule
        vector<vector<int>> adj(numCourses);
        for(int courses = 0; courses < prerequisites.size(); ++courses){
            adj[prerequisites[courses][1]].push_back(prerequisites[courses][0]);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> dfsVisited(numCourses, false); 

        for(int course = 0; course < numCourses; ++course){
            if(!visited[course]){
                if(dfsCall(course, adj, visited, dfsVisited)){
                    return false;
                }
            }
        }

        return true;
    }
};