class Solution {
public:
    int passThePillow(int n, int time) {
        int index = 1 , dir = -1;

        while(time--){
            if(index == 1 || index == n){
                dir*=-1;
            }

            index+=dir;
        }
        return index;
    }
};