class Solution {
public:
    int minimumPushes(string word) {
        int freq[26]= {0};

        memset(freq, 0 ,sizeof(freq));

        for(char ch  : word){
            freq[ch - 'a']++;
        }

        sort(freq , freq+26, greater<int>());

        int dist = 0 , res = 0;
        int cost = 0 ;
        for(int i = 0; i < 26; i++){
            if (i%8==0) cost++ ;
            if(freq[i] > 0){
                dist++;
                res  += freq[i] * cost ;
            }
        } 
        
        return res;
    }
};