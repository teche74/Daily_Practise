class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int res = 0;
        for(auto t : nums){
            if(st.find(t-1) == st.end()){
                int count =0;
                int val = t;
                while(st.find(val) != st.end()){
                    count++;
                    val++;
                } 
                res = max(res,count); 
            }
        }
        return res;
    }
};