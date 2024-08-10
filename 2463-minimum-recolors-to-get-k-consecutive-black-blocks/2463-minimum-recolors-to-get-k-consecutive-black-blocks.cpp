class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int low = 0 , high =  0, size = blocks.size() , res = size;

        int white = 0 ;

        while(high < size){
            white += (blocks[high] == 'W');

            while(high - low + 1 > k){
                white -= (blocks[low] == 'W');
                low++;
            }

            if(high - low + 1 == k) res = min(res, white);
            high++;
        }

        return res;

    }
};