class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        if (n == 1) return {0};
        
        vector<int>res;
        queue<int>q;

        unordered_map<int,int>indegree;
        unordered_map<int, vector<int>>graph;

        for(auto t : edges){
            indegree[t[0]]++;
            indegree[t[1]]++;
            graph[t[0]].push_back(t[1]);
            graph[t[1]].push_back(t[0]);
        }


        for(auto t : indegree){
            if(t.second == 1){
                q.push(t.first);
            }
        }

        while(q.size()){
            res.clear();
            int size = q.size();

            while(size--){
                int front = q.front();q.pop();
                res.push_back(front);

                for(auto t : graph[front]){
                    indegree[t]--;

                    if(indegree[t] == 1){
                        q.push(t);
                    }
                }
            }
        }

        return res;
    }
};