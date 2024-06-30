class Solution {
public:
    pair<int, int> bfs(int start, const vector<vector<int>>& g) {
        int n = g.size();
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        
        int far = start;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (int neighbor : g[node]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                    if (dist[neighbor] > dist[far]) {
                        far = neighbor;
                    }
                }
            }
        }
        
        return {far, dist[far]};
    }
    
    pair<int, vector<int>> find_d_And_c(const vector<vector<int>>& g) {
        int n = g.size();
        auto [far_from_start, _] = bfs(0, g);
        auto [far_from_end, d] = bfs(far_from_start, g);

        vector<int> dist(n, -1);
        queue<int> q;
        q.push(far_from_start);
        dist[far_from_start] = 0;

        vector<int> par(n, -1);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (int neighbor : g[node]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[node] + 1;
                    par[neighbor] = node;
                    q.push(neighbor);
                }
            }
        }

        vector<int> path;
        int node = far_from_end;
        while (node != -1) {
            path.push_back(node);
            node = par[node];
        }

        int path_len = path.size();
        if (path_len % 2 == 0) {
            return {d, {path[path_len / 2 - 1], path[path_len / 2]}};
        } else {
            return {d, {path[path_len / 2]}};
        }
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        vector<vector<int>> tree1(n);
        vector<vector<int>> tree2(m);

        for (auto& edge : edges1) {
            tree1[edge[0]].push_back(edge[1]);
            tree1[edge[1]].push_back(edge[0]);
        }

        for (auto& edge : edges2) {
            tree2[edge[0]].push_back(edge[1]);
            tree2[edge[1]].push_back(edge[0]);
        }

        auto [diameter1, centers1] = find_d_And_c(tree1);
        auto [diameter2, centers2] = find_d_And_c(tree2);

        int maxCenterDistance = 0;
        for (int c1 : centers1) {
            for (int c2 : centers2) {
                maxCenterDistance = max(maxCenterDistance, 1);
            }
        }

        return max({diameter1, diameter2, (diameter1 + 1) / 2 + (diameter2 + 1) / 2 + 1});
    }
};