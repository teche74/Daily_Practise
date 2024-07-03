class Solution {
public:
    string longestPrefix(string s) {
        int size = s.size();

        int pi_table[size];

        memset(pi_table, 0 ,sizeof(pi_table));

        int i = 0 , j = 1; 

        while(j < size){
            if(s[i] == s[j]){
                pi_table[j] = i+1;
                i++;
                j++;
            }
            else{
                if(i != 0){
                    i = pi_table[i-1]; 
                }
                else{
                    pi_table[j] = 0;
                    j++;
                }
            }
        }

        return s.substr(0,pi_table[size-1]);
    }
};