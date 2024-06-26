class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int res = 0;
        for(auto val : st){
            if(st.find(val - 1) == st.end()){
                int curr = val;
                int len = 0;

                while(st.find(curr) != st.end()){
                    curr++, len++;
                }
                res = max(res, len);
            }
        }
        return res;
    }
};