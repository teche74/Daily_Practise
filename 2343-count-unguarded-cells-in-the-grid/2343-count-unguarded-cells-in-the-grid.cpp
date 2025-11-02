class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        unordered_map<int, vector<int>> row_map, col_map;
        set<pair<int,int>> occupied;

        for (auto &g : guards) {
            row_map[g[0]].push_back(g[1]);
            col_map[g[1]].push_back(g[0]);
            occupied.insert({g[0], g[1]});
        }
        for (auto &w : walls) {
            row_map[w[0]].push_back(w[1]);
            col_map[w[1]].push_back(w[0]);
            occupied.insert({w[0], w[1]});
        }

        for (auto &it : row_map) sort(it.second.begin(), it.second.end());
        for (auto &it : col_map) sort(it.second.begin(), it.second.end());

        set<pair<int,int>> guarded;

        for (auto &g : guards) {
            int r = g[0], c = g[1];

            auto &row = row_map[r];
            auto it = lower_bound(row.begin(), row.end(), c);
            int left = (it == row.begin()) ? -1 : *(prev(it));
            for (int j = c-1; j > left; j--) {
                if (occupied.count({r,j})) break;
                guarded.insert({r,j});
            }

            int right = (next(it) == row.end()) ? n : *(next(it));
            for (int j = c+1; j < right; j++) {
                if (occupied.count({r,j})) break;
                guarded.insert({r,j});
            }

            auto &col = col_map[c];
            auto it2 = lower_bound(col.begin(), col.end(), r);
            int up = (it2 == col.begin()) ? -1 : *(prev(it2));
            for (int i = r-1; i > up; i--) {
                if (occupied.count({i,c})) break;
                guarded.insert({i,c});
            }

            int down = (next(it2) == col.end()) ? m : *(next(it2));
            for (int i = r+1; i < down; i++) {
                if (occupied.count({i,c})) break;
                guarded.insert({i,c});
            }
        }

        long long total_empty = (long long)m * n - occupied.size();
        long long unguarded = total_empty - guarded.size();
        return (int)unguarded;
    }
};
