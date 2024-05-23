class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();

        if(size == 0 ) return  0;
        if(size == 1) return cost[size-1];

        int prev1 = cost[0], prev2 = cost[1];

        for(int i =2; i < size; i++){
            int curr = cost[i] + min(prev1,prev2);
            prev1= prev2;
            prev2 =curr;
        }

        return min(prev1, prev2);
    }
};