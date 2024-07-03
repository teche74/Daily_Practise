class Solution {
public:
    bool isPalindrome(string s) {

        transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ 
            return tolower(c); 
        });

        int low = 0 , high = s.size()-1, size =s.size();

        while(low < high){
            while (low < high && (!isalnum(s[low]) || isspace(s[low])))
                low++;

            while (low < high && (!isalnum(s[high]) || isspace(s[high])))
                high--;

            if(low < high && s[low] != s[high]){
                return false;
            }

            low++;
            high--;
        } 

        return true;
    }
};