class Solution {
public:
    char next(char ch){
        if(ch == 'a') return 'e';
        else if(ch == 'e') return 'i';
        else if(ch =='i') return 'o';
        return 'u';
    }
    int longestBeautifulSubstring(string word) {
        int low = 0 , high = 1 , size = word.size() ,res = 0;

        while(high  < size){
            if( !(word[high] == next(word[high-1]) || word[high] == word[high-1])  ){
                low = high;
            }
            if(word[low] == 'a' && word[high] == 'u') res = max(res,high - low+1);
            high++;
        }

        return res;
    }
};