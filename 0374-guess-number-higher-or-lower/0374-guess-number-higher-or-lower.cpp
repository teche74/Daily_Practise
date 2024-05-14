/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long index =0;

        for(long long i = n ; i>=1 ; i/=2){
            while(index + i <= n && guess(index + i) >= 0) index+=i;
        }

        return index;
    }
};