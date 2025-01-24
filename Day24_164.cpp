class Solution {
    void dfsGetEndTime(int node, vector<vector<int>> graph, vector<bool>& visited, stack<int>& end_time){
        visited[node] = true;
        for(auto neighbor : graph[node]){
            if(!visited[neighbor]){
                dfsGetEndTime(neighbor, graph, visited, end_time);
            }
        }
        end_time.push(node);
    }

    void dfsFillScc(int node, vector<vector<int>> rGraph, vector<bool>& visited, vector<int>& temp){
        visited[node] = true;
        if(rGraph[node].size() == 0) return;
        temp.push_back(node);
        for(auto neighbor : rGraph[node]){
            if(!visited[neighbor]){
                dfsFillScc(neighbor, rGraph, visited, temp);
            }
        }
    }

    void dfsCheckOutDegree(int node, vector<vector<int>> graph, unordered_map<int, int>& mp, vector<bool>& visited, bool& flag){
        visited[node] = true;
        for(auto neighbor : graph[node]){
            if(mp[neighbor] != 1){
                flag = false;
                return;
            }
            if(!visited[neighbor]){
                dfsCheckOutDegree(neighbor, graph, mp, visited, flag);
            }
        }
    }

public:
    vector<string> maxNumOfSubstrings(string s) {
        // Q. Maximum Number of Non-Overlapping Substrings
        int n = s.length();
        vector<int> firstOccur(26, INT_MAX);
        vector<int> lastOccur(26, INT_MIN);
        for(int index = 0; index < n ; ++index){
            firstOccur[s[index] - 'a'] = min(firstOccur[s[index] - 'a'], index);
            lastOccur[s[index] - 'a'] = index;
        }

        vector<vector<int>> graph(26);
        for(int neighbor = 0; neighbor < n; ++neighbor){
            for(int node = 0; node < 26; ++node){
                if(firstOccur[s[neighbor] - 'a'] != INT_MAX){
                    if(firstOccur[node] <= neighbor && lastOccur[node] >= neighbor){
                        graph[node].push_back(s[neighbor] - 'a');
                    }
                }
            }
        }

        n = 26;
        vector<bool> visited(n, false);
        stack<int> end_time;
        for(int node = 0; node < n; ++node){
            if(!visited[node]){
                dfsGetEndTime(node, graph, visited, end_time);
            }
        }

        vector<vector<int>> rGraph(26);
        for(int node = 0; node < n; ++node){
            for(int neighbor = 0; neighbor < graph[node].size(); ++neighbor){
                rGraph[graph[node][neighbor]].push_back(node);
            }
        }

        vector<bool> visit(n, false);
        vector<vector<int>> strongConnectCompo;
        while(!end_time.empty()){
            int currNode = end_time.top();
            end_time.pop();
            if(!visit[currNode]){
                vector<int> temp;
                dfsFillScc(currNode, rGraph, visit, temp);
                strongConnectCompo.push_back(temp);
            }
        }

        vector<string> answer;
        for(auto vect : strongConnectCompo){
            vector<bool> vis(n, false);
            if(vect.size()){
                unordered_map<int, int> mp;
                for(auto element : vect){
                    mp[element] = 1;
                }
                bool flag = true;
                dfsCheckOutDegree(vect[0], graph, mp, vis, flag);
                if(flag){
                    int minIndex = 1e9;
                    int maxIndex = -1;
                    for(auto element : vect){
                        minIndex = min(minIndex, firstOccur[element]);
                        maxIndex = max(maxIndex, lastOccur[element]);
                    }
                    answer.push_back(s.substr(minIndex, maxIndex - minIndex + 1));
                }
            }
        }

        return answer;
    }
};