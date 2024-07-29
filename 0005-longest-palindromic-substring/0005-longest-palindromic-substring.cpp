class Solution {
public:
    string longestPalindrome(string s) {
        // apprach 1 : centre expand theorum

        // function<string(void)> centreExpand = [&](){
        //     int size =s.size();

        //     function<int(int ,int)> find_len = [&](int low,  int high){
        //         while(low >= 0 && high < size && s[low] == s[high]){
        //             low--;
        //             high++;
        //         }

        //         return high - low-1;
        //     };

        //     int ind = 0 , len=0;

        //     for(int i = 0 ; i <size; i++){
        //         int l1 = find_len(i,i);
        //         int l2 = find_len(i,i+1);

        //         int max_len = max(l1,l2);

        //         if(max_len > len){
        //             len = max_len;
        //             ind = i - (max_len - 1)/2;
        //         }
        //     }

        //     return s.substr(ind,len);
        // }; 

        // return centreExpand();



        // second approach : manchers algo;

        function<string(void)> manchars = [&](){
            int size = s.size();

            string str = "@";

            for(char ch : s){
                str.push_back('|');
                str.push_back(ch);
            }

            str.push_back('|');
            str.push_back('$');

            vector<int>lps(str.size(),0);

            int right = 0 , centre = 0;

            for(int i = 1; i < str.size()-1 ; i++){
                int mirror = 2 * centre - i;

                if(i < right){
                    lps[i] = min(right - i , lps[mirror]);
                }

                while(str[i + lps[i] + 1] == str[i - lps[i] - 1]){
                    lps[i]++;
                }

                if(i + lps[i] > right){
                    centre = i ;
                    right = i + lps[i];
                }
            }

            int max_len = 0 , max_centre = 0;

            for(int i = 1 ; i < lps.size()-1 ; i++){
                if(lps[i] > max_len){
                    max_len = lps[i];
                    max_centre = i;
                }
            } 


            return s.substr( (max_centre - max_len)/2 , max_len);
        } ;

        return manchars();
    }
};