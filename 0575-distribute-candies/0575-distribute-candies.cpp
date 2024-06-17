class Solution {
public:
    int distributeCandies(vector<int>& nums) {
        set<int>st;
        for(int val:nums) st.insert(val);
        return min(nums.size()/2, st.size());
    }
};