class Solution {
public:
    int minCost(string colors, vector<int>& time) {
        // int size = colors.size();

        // vector<vector<int>>dp(size+1 , vector<int>(size+1,-1));

        // function<int(int, int)>calcMinTime = [&](int prev , int curr){
        //     if(curr >= size){
        //         return 0;
        //     }

        //     if(dp[(prev == -1 ? size : prev)][curr] != -1) return dp[(prev == -1 ? 100001 : prev)][curr];

        //     int no_change = INT_MAX , remove_this = INT_MAX;

        //     if(prev == -1 || (prev != -1 && colors[curr] != colors[prev])){
        //         no_change = calcMinTime(curr,  curr+1); 
        //     }
        //     else{
        //         remove_this = min(time[prev] + calcMinTime(curr, curr+1) , time[curr]  + calcMinTime(prev, curr+1));
        //     }

        //     return dp[(prev == -1 ? size : prev)][curr] = min(no_change , remove_this);   
        // };

        // return calcMinTime(-1, 0);

        int size = colors.size();

        int res = 0;

        for(int i = 0; i < size; i++){

            if(i > 0 && colors[i] == colors[i-1]){
                res += min(time[i] , time[i-1]);
                time[i] = max(time[i] , time[i-1]);
            }
        }

        return res;
    }
    
};