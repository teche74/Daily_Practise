class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = 0;

        while(numBottles >= numExchange){
            res+=numExchange;
            numBottles-=numExchange;
            numBottles+=1;
        }

        if(numBottles > 0){
            res +=numBottles;
        }
        return res;
    }
};