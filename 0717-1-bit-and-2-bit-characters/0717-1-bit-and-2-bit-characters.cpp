class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int index = bits.size() -2 , ones= 0;

        while(index >= 0 && bits[index] != 0){
            index--;
            ones++;
        }


        return ones % 2 <= 0;
    }
};