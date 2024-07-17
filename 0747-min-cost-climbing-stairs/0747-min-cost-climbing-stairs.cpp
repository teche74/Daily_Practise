class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        int prev = cost[1] ,pprev= cost[0];

        for(int i = 2; i < size ; i++){
            int curr = cost[i] + min(prev,pprev);
            pprev = prev ;
            prev = curr;
        }

        return min(prev,pprev);
    }
};