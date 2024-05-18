class Solution {
public:
    int strStr(string haystack, string needle) {
        auto lps_helper = [&haystack, &needle]()->int{
            string temp = needle + '$' + haystack;

            int lps[temp.size()];
            memset(lps,0,sizeof(lps));

            int i =0, j= 1 , size = temp.size();

            while(j < size){
                if(temp[i] == temp[j]){
                    lps[j] =i+1;
                    i++;
                    j++;
                }
                else{
                    if(i!=0){
                        i = lps[i-1];
                    }
                    else{
                        lps[j] = 0;
                        j++;
                    }
                }
            }

            for(int i =0 ; i < temp.size() ;i++){
                if(lps[i] == needle.size()){
                    return i - 2 * needle.size();
                }
            }

            return -1;
        };

        return lps_helper();
    }
};