class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int cnt{0}, size = hours.size();

        for(int i =0; i < size ; i++){
            if(hours[i] >= target) cnt++;
        }
        return cnt;
    }
};