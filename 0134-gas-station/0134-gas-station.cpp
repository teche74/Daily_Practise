class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = cost.size();

        vector<int>diff(size, 0);

        for(int i = 0 ; i < size ; i++){
            diff[i] = gas[i] -cost[i];
        }

        int total = 0 , start =  0, curr = 0;

        for(int i = 0; i  < size; i++){
            curr += diff[i];
            total += diff[i]; 

            if(curr < 0){
                curr = 0;
                start = i+1;
            }

        }

        return total >= 0  ? start : -1;
    }
};