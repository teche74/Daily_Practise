class Solution {
public:
    int beautySum(string s) {
        int low = 0 , high = 0 , size = s.size() , res = 0, count = 0;

        int freq[26];


        for(low = 0 ; low < size ; low++){
            memset(freq, 0, sizeof(freq));

            for(high = low ; high < size ; high++){

                freq[s[high] - 'a']++;

                int mini = INT_MAX, maxi = INT_MIN;
                for(int i =0; i <26; i ++){
                    maxi = max(freq[i], maxi);
                    if(freq[i] != 0)  mini = min(mini, freq[i]);
                }

                res+=(maxi - mini);
            }
        }

        return res;
    }
};