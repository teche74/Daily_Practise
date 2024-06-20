class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());

        double sum = accumulate(salary.begin(), salary.end(), 0);

        sum-=salary[0] , sum-=salary[salary.size()-1];  

        return sum/(salary.size()-2); 
    }
};