class Solution {
public:
    bool solve(int index, int jump, vector<int>& stones, unordered_map<int, unordered_map<int, bool>>& memo) {
        if (index == stones.size() - 1) return true;
        if (memo.find(index) != memo.end() && memo[index].find(jump) != memo[index].end()) return memo[index][jump];

        for (int step = jump - 1; step <= jump + 1; step++) {
            if (step > 0) {
                int nextPos = stones[index] + step;
                auto it = lower_bound(stones.begin(), stones.end(), nextPos);
                if (it != stones.end() && *it == nextPos) {
                    int nextIndex = it - stones.begin();
                    if (solve(nextIndex, step, stones, memo)) {
                        memo[index][jump] = true;
                        return true;
                    }
                }
            }
        }

        memo[index][jump] = false;
        return false;
    }

    bool canCross(vector<int>& stones) {
        if (stones[1] != 1) return false; 

        unordered_map<int, unordered_map<int, bool>> memo;
        return solve(0, 0, stones, memo);
    }
};
