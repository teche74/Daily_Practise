class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<double, int>>> adj(n);
        vector<double> prob(n, 0.0);

        for (int i = 0; i < edges.size(); i++) {
            int edge1 = edges[i][0], edge2 = edges[i][1];
            adj[edge1].push_back({succProb[i], edge2});
            adj[edge2].push_back({succProb[i], edge1});
        }

        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});
        prob[start_node] = 1.0;

        while (!pq.empty()) {
            auto [cur_prob, node] = pq.top();
            pq.pop();

            if (node == end_node) 
                return cur_prob;

            for (auto& [next_prob, neighbor] : adj[node]) {
                double new_prob = cur_prob * next_prob;
                if (new_prob > prob[neighbor]) {
                    prob[neighbor] = new_prob;
                    pq.push({new_prob, neighbor});
                }
            }
        }
        return 0.0;
    }
};
