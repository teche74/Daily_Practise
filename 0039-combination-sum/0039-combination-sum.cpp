class Solution {
public:
    unordered_map<string, vector<vector<int>>> memo;

    vector<vector<int>> solve(int index, vector<int>& arr, int val) {
        string key = to_string(index) + "-" + to_string(val);
        
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        if (val == 0) {
            return {{}};
        }

        if (index >= arr.size() || val < 0) {
            return {};
        }

        vector<vector<int>> res;

        if (val - arr[index] >= 0) {
            vector<vector<int>> include = solve(index, arr, val - arr[index]);
            for (auto& combination : include) {
                combination.emplace_back(arr[index]);
                res.emplace_back(combination);
            }
        }

        vector<vector<int>> exclude = solve(index + 1, arr, val);
        res.insert(res.end(), exclude.begin(), exclude.end());

        memo[key] = res;
        return res;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        memo.clear();
        return solve(0, candidates, target);
    }
};
