class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
         vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);
        vector<set<int>> ancestors(n);
        
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                ancestors[neighbor].insert(node);
                for (int anc : ancestors[node]) {
                    ancestors[neighbor].insert(anc);
                }
                if (--inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        vector<vector<int>> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
        }

        return result;
    }
};