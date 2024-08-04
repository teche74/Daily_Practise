class Solution {
public:
    bool closeStrings(string word1, string word2) {

        int n = word1.size(), m = word2.size();

        if(n != m) return false;


        int freq_w1[26] , freq_w2[26];

        memset(freq_w1,0,sizeof(freq_w1));
        memset(freq_w2,0,sizeof(freq_w2));

        for(int i = 0 ;i < n ; i++){
            freq_w1[word1[i] - 'a']++;
            freq_w2[word2[i] - 'a']++;
        }

        for(int i = 0 ;i  < 26 ; i++){
            if(freq_w1[i] != 0 && freq_w2[i] == 0 || freq_w1[i] == 0 && freq_w2[i] != 0) return false;  
        }

        sort(freq_w1 , freq_w1 + 26);
        sort(freq_w2 , freq_w2 + 26);

        for(int i = 0 ;i < 26; i++){
            if(freq_w1[i] != freq_w2[i]) return false;
        }

        return true;
    }
};