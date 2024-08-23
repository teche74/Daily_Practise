class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int zero = 0, one = 0;
        for (int student : students) {
            if (student == 0) zero++;
            else one++;
        }
        for (int sandwich : sandwiches) {
            if (sandwich == 0) {
                if (zero == 0) return one;
                zero--;
            } else {
                if (one == 0) return zero;
                one--;
            }
        }
        return 0;
    }
};
