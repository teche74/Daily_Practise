class Solution {
public:

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<int>> adj;

        for (auto con : connections) {
            adj[con[0]].emplace_back(con[1]);
            adj[con[1]].emplace_back(con[0]);
        }

        int time = 1;

        vector<bool> vis(n, false);
        vector<int> time_when_node_first_visited(n, 0);
        vector<int> min_time_to_visit_node(n, 0);
        vector<vector<int>> res;

        function<void(int, int)> dfs = [&](int node, int parent) {
            vis[node] = true;
            time_when_node_first_visited[node] = min_time_to_visit_node[node] = time++;

            for (auto t : adj[node]) {
                if (t == parent) continue;

                if (!vis[t]) {
                    dfs(t, node);

                    min_time_to_visit_node[node] = min(min_time_to_visit_node[node], min_time_to_visit_node[t]);

                    if (min_time_to_visit_node[t] > time_when_node_first_visited[node]) {
                        res.push_back({t, node});
                    }
                } else {
                    min_time_to_visit_node[node] = min(min_time_to_visit_node[node], time_when_node_first_visited[t]);
                }
            }
        };

        dfs(0, -1);

        return res;
    }
};
