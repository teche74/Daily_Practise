class DisjointSet {
private:
    vector<int> parent, unionbysize;

public:
    DisjointSet(int size) {
        parent.resize(size + 1);
        unionbysize.resize(size + 1);

        for (int i = 0; i <= size; i++) {
            parent[i] = i;
            unionbysize[i] = 1;
        }
    }

    int findParent(int node) {
        if (parent[node] != node) {
            parent[node] = findParent(parent[node]);
        }

        return parent[node];
    }

    void do_union(int node1, int node2) {
        int parent_of_node1 = findParent(node1);
        int parent_of_node2 = findParent(node2);

        if (parent_of_node1 != parent_of_node2) {
            if (unionbysize[parent_of_node1] > unionbysize[parent_of_node2]) {
                parent[parent_of_node2] = parent_of_node1;
                unionbysize[parent_of_node1] += unionbysize[parent_of_node2];
            } else {
                parent[parent_of_node1] = parent_of_node2;
                unionbysize[parent_of_node2] += unionbysize[parent_of_node1];
            }
        }
    }
};

class Solution {
public:
    int Krush(int size, vector<vector<int>>& edges, int exclude_index,int include_index) {
        DisjointSet ds(size);
        int total = 0;
        int edge_count = 0;

        if (include_index != -1) {
            total += edges[include_index][2];
            ds.do_union(edges[include_index][0], edges[include_index][1]);
            edge_count++;
        }

        for (int i = 0; i < edges.size(); ++i) {
            if (i == exclude_index)
                continue;

            int node1 = edges[i][0];
            int node2 = edges[i][1];
            int weight = edges[i][2];

            if (ds.findParent(node1) != ds.findParent(node2)) {
                ds.do_union(node1, node2);
                total += weight;
                edge_count++;
            }
        }
        if (edge_count != size - 1)
            return INT_MAX;

        return total;
    }

    vector<vector<int>>
    findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); i++) {
            edges[i].emplace_back(i);
        }

        sort(edges.begin(), edges.end(),
             [&](vector<int>& a, vector<int>& b) { return a[2] < b[2]; });

        int Krush_value = Krush(n, edges, -1, -1);

        vector<int> critical , psuedo;

        for (int i = 0; i < edges.size(); i++) {
            if (Krush(n, edges, i, -1) > Krush_value) {
                critical.push_back(edges[i][3]);
            } else if (Krush(n, edges, -1, i) == Krush_value) {
                psuedo.push_back(edges[i][3]);
            }
        }

        return {critical, psuedo};
    }
};