class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;

        while(numBottles >= numExchange){
            int extra = (numBottles / numExchange);
            res += extra;
            numBottles = extra + (numBottles % numExchange);
        }

        return res;
    }
};