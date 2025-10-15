class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int,int>map;

        for(int x : nums) map[x]++;

        int sum = 0;

        for(auto it : map){
            if(it.second % k == 0){
                sum += (it.first * it.second);
            }
        }

        return sum;
    }
};