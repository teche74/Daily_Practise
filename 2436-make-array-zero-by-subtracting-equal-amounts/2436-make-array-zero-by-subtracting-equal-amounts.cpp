class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> uni;
        
        for (int num : nums) {
            if (num > 0) {
                uni.insert(num);
            }
        }
        
        return uni.size();
    }
};