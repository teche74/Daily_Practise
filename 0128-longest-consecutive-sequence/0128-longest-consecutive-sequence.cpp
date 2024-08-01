class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>map;

        for(auto t : nums){
            map[t]++;
        }
        int res = 0;
        for(auto t : nums){
            if(map.find(t-1) == map.end()){
                int count =0;
                int val = t;
                while(map.find(val) != map.end()){
                    count++;
                    val++;
                } 
                res = max(res,count); 
            }
        }
        return res;
    }
};