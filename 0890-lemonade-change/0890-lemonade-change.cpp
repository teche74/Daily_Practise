class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int size = bills.size();
        int total = 0, coins_five = 0 , coins_ten = 0 ;


        for(int i =0 ; i < size ; i++){
            coins_five += (bills[i] == 5);

            if(bills[i] == 10){
                if(coins_five >= 1){
                    coins_five-=1;
                    coins_ten++;
                }
                else{
                    return false;
                }
            }
            else if(bills[i] == 20){
                if(coins_five >= 1 && coins_ten >=1 ){
                    coins_five -= 1;
                    coins_ten -= 1;
                }
                else if(coins_five >= 3){
                    coins_five -= 3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};