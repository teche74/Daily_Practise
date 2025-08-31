class Solution {
public:
    vector<int> findOrder(int nodes, vector<vector<int>>& edges) {
        vector<int>indegree(nodes, 0);
        unordered_map<int, vector<int>>graph;

        for(auto t : edges){
            graph[t[1]].push_back(t[0]);
            indegree[t[0]]++;
        }

        queue<int>q;

        for(int i = 0; i < nodes ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int visited = 0;
        vector<int> res;

        while(q.size()){
            int curr = q.front();q.pop();
            res.push_back(curr);
            visited++;

            for(int next : graph[curr]){
                indegree[next]--;
                if(indegree[next] == 0){
                    q.push(next);
                }
            }
        }

        if(visited == nodes) return res;
        return {};
    }
};