class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int size = nums.size();
        
        vector<int>res(size,0);
        deque<int>dq;

        dq.push_back(0);

        res[0] = nums[0];

        for(int i =1; i < size; i++){
            while( !dq.empty() && dq.front() < i-k ){
                dq.pop_front();
            }

            res[i] = nums[i] + res[dq.front()];

            while(!dq.empty() && res[dq.back()] <= res[i]){
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return res[size-1];
    }
};