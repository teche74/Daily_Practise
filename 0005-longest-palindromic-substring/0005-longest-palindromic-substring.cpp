class Solution {
public:
    string machers(const string &s){
        string temp = "$";

        for(char ch : s){
            temp.push_back('|');
            temp.push_back(ch);
        }

        temp+="|@";

        vector<int>lps(temp.size(),0);

        int centre = 0, right = 0 ;

        for(int i = 1; i <temp.size()-1 ;i++){
            int mirror = 2 * centre - i;

            if(i<right){
                lps[i] = min(lps[mirror],right - i);
            }

            while(temp[i - 1 - lps[i]] == temp[i+1 + lps[i]]){
                lps[i]++;
            }

            if(i + lps[i] >right){
                centre = i;
                right = i + lps[i];
            }
        }

        int max_len = 0 , max_centre = 0;

        for(int i =1 ; i  < temp.size()-1 ; i++){
            if(lps[i] > max_len){
                max_len = lps[i];
                max_centre = i;
            }
        }

        return s.substr((max_centre - max_len)/2, max_len);       
    }
    string longestPalindrome(string s) {
        return machers(s); 
    }
};