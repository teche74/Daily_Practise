class Solution {
public:
    int find_func(int a, vector<int>& p) {
        if (a == p[a]) return a;
        return p[a] = find_func(p[a], p);
    }

    void union_func(int a, int b, vector<int>& size, vector<int>& p) {
        int parentA = find_func(a, p);
        int parentB = find_func(b, p);
        if (parentA != parentB) {
            if (size[parentB] < size[parentA]) swap(parentA, parentB);
            p[parentA] = parentB;
            size[parentB] += size[parentA];
        }
    }

    int largestComponentSize(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        vector<int> parent(maxNum + 1), size(maxNum + 1, 1);

        for (int i = 0; i <= maxNum; ++i) {
            parent[i] = i;
        }

        for (int num : nums) {
            for (int fact = 2; fact * fact <= num; ++fact) {
                if (num % fact == 0) {
                    union_func(num, fact, size, parent);
                    union_func(num, num / fact, size, parent);
                }
            }
        }

        unordered_map<int, int> map;
        int res = 0;

        for (int num : nums) {
            int leader = find_func(num, parent);
            map[leader]++;
            res = max(res, map[leader]);
        }

        return res;
    }
};
