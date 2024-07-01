class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int size = nums.size();
        long long low =0, high =0, res =0, count =0;
        deque<long long> max_dq , min_dq;

        while( high < size){
            while(!max_dq.empty() && nums[max_dq.back()] < nums[high]) max_dq.pop_back();
            max_dq.push_back(high);

            while(!min_dq.empty() && nums[min_dq.back()] > nums[high]) min_dq.pop_back();
            min_dq.push_back(high);

            while(abs(nums[high] - nums[min_dq.front()]) > 2 || abs(nums[high] - nums[max_dq.front()]) > 2){
                if(min_dq.front() == low) min_dq.pop_front();
                if(max_dq.front() == low) max_dq.pop_front();
                low++;
            }
            res+=(high - low + 1);
            high++;
        }
        return res;
    }
};