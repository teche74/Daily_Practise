class Solution {
public:
    string longestPalindrome(string s) {
        // apprach 1 : centre expand theorum

        function<string(void)> centreExpand = [&](){
            int size =s.size();

            function<int(int ,int)> find_len = [&](int low,  int high){
                while(low >= 0 && high < size && s[low] == s[high]){
                    low--;
                    high++;
                }

                return high - low-1;
            };

            int ind = 0 , len=0;

            for(int i = 0 ; i <size; i++){
                int l1 = find_len(i,i);
                int l2 = find_len(i,i+1);

                int max_len = max(l1,l2);

                if(max_len > len){
                    len = max_len;
                    ind = i - (max_len - 1)/2;
                }
            }

            return s.substr(ind,len);
        }; 

        return centreExpand();
    }
};