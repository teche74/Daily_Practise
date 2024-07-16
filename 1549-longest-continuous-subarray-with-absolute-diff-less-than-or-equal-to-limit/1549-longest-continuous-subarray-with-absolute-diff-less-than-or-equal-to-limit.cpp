class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int>maxi , mini;
        int low = 0, high = 0 , size = nums.size() , res = 0;

        while(high  < size){

            while(!maxi.empty() && nums[maxi.back()] < nums[high]){
                maxi.pop_back();
            }

            maxi.push_back(high);

            while(!mini.empty() && nums[mini.back()] > nums[high]){
                mini.pop_back();
            }

            mini.push_back(high);


            while(!mini.empty() && !maxi.empty() && abs(nums[mini.front()] - nums[maxi.front()]) > limit ){
                if(low == mini.front()){
                    mini.pop_front();
                }

                if(low == maxi.front()){
                    maxi.pop_front();
                }

                low++;
            }


            res = max(res, high - low+1);
            high++;
        }
        return res;
    }
};