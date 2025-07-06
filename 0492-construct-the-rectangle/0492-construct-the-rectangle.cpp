class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = sqrt(area);
        int diff= INT_MAX;
        vector<int>res{0,0};

        for(int i = 1 ; i <= w ; i++){
            if(area % i==0){
                int l = area/i;
                if(abs(l - i) < diff){
                    res[0] = l;
                    res[1] = i;
                    diff = abs(l -i);
                }
            }
        }

        return res;
    }
};