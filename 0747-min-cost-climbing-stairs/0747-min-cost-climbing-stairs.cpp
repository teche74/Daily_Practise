// simple recursion

// class Solution {
// public:

//     int solve(int index, vector<int> & cost){
//         if (index >= cost.size()) {
//             return 0;
//         }

        
//         int takeOneStep = cost[index] + solve(index + 1, cost);
//         int takeTwoSteps = cost[index] + solve(index + 2, cost);
        
//         return min(takeOneStep, takeTwoSteps);
//     }

//     int minCostClimbingStairs(vector<int>& cost) {
//         return min(solve( 0, cost) , solve(1,cost));
//     }
// };

// memo

// class Solution {
// public:
//     vector<int> memo;
//     int solve(int index, vector<int> & cost){
//         if (index >= cost.size()) {
//             return 0;
//         }

//         if(memo[index] != -1) return memo[index];
        
//         int takeOneStep = cost[index] + solve(index + 1, cost);
//         int takeTwoSteps = cost[index] + solve(index + 2, cost);
        
//         return memo[index] = min(takeOneStep, takeTwoSteps);
//     }

//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         memo.assign(n, -1);
//         return min(solve( 0, cost) , solve(1,cost));
//     }
// };



class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();

        int prev = cost[0] , prev2 = cost[1];

        for(int i =2; i < size; i++){
            int curr = cost[i] + min(prev,prev2);
            prev = prev2;
            prev2 =curr;
        }

        return min(prev,prev2);
    }
};
