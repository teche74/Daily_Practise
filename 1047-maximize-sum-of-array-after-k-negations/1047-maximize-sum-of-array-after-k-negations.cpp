class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>>pq(nums.begin() , nums.end());

        while(pq.size() && pq.top() < 0 && k){
            int top = pq.top();pq.pop();
            k--;
            pq.push(abs(top));
        }


        int sum = 0;
        
        if(k % 2 != 0){
            if(pq.size()){
                sum -= pq.top();pq.pop();
            }
        }

        while(pq.size()){
            sum += pq.top();
            pq.pop();
        }

        return sum;
    }
};