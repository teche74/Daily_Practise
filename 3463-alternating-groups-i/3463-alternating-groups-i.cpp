class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int low = 0 , high = 0 , size = colors.size(), res = 0;

        while(high <= size+1 )
        {
            if(high > 0 && colors[high % size]  == colors[(high - 1) % size]){
                low = high;
            }

            while(high - low + 1 > 3){
                low++;
            }
            
            if(high - low + 1 == 3)
            res += (high - low + 1 == 3);
            high++;
        }

        return res;
    }
};