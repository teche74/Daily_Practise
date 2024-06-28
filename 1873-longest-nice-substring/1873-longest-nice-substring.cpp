class Solution {
public:
    string longestNiceSubstring(string s) {
        int low =  0 , high = 0 ,size = s.size();
        int ind = 0 , len = 0;


        for(;low <size ; low++){
            vector<pair<int,int>>freq(26,{0,0});
            int uni = 0;

            for(high = low ; high < size ; high++){
                
                if(isupper(s[high])){
                    uni += (freq[s[high] - 'A'].second == 0);
                    freq[s[high] - 'A'].second++;
                } 
                else{
                    uni += (freq[s[high] - 'a'].first == 0);
                    freq[s[high] - 'a'].first++;
                }


                bool nice = true;
                for (int i = 0; i < 26; ++i) {
                    if ((freq[i].first > 0 && freq[i].second == 0) || (freq[i].first == 0 && freq[i].second > 0)) {
                        nice = false;
                        break;
                    }
                }

                if (nice) {
                    if (high - low + 1 > len) {
                        len = high - low+1;
                        ind =  low;
                    }
                }
            }

        }
        return len == 0 ? "" : s.substr(ind,len);
    }
};