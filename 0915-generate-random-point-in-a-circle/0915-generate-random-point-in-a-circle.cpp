class Solution {
    double rad, x, y; 
public:
    Solution(double radius, double x_center, double y_center) {
        rad = radius;
        x = x_center;
        y = y_center;
    }
    
    vector<double> randPoint() {
        double distance = sqrt((double)rand() / RAND_MAX) * rad;
        double angle = ((double)rand() / RAND_MAX) * 2 * M_PI;

        double rand_x = x + distance * cos(angle);
        double rand_y = y + distance * sin(angle);

        return {rand_x, rand_y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */