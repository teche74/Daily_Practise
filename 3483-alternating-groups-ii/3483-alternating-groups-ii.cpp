class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int low = 0 , high = 1 , size = colors.size() , res = 0;

        while(low < size){
            if(colors[high % size] == colors[(high-1) % size]){
                // cout<<"Error : "<<high<<endl;
                low = high;
            }

            while(high - low + 1 >= k){
                if(high - low + 1  == k){
                    // cout<<"Complete range : "<<low <<" "<<high<<endl;
                    res++;
                }
                low++;
            }
            // cout<<"high : "<<high<<endl;
            high++;
        }

        return res;
        
    }
};