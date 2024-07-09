class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());

        int res = 0;

        for(int i =0 ;i <nums.size() ; i++){
            if(st.find(nums[i]-1) == st.end()){
                int len =1;
                int val = nums[i]+1;
                while(st.find(val) != st.end()){
                    val++;
                    len++;
                }
                res = max(res, len);
            }
        }
        return res;
    }
};