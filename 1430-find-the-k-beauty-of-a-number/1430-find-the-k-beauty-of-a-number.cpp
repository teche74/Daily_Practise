class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string temp  = to_string(num);

        int size = temp.size(), ct=  0;

        for(int i  = 0 ; i  <= size-k ; i++){
            int val =  stoi(temp.substr(i,k));

            if(val != 0 && num % val == 0){
                ct++;
            }
        }
        
        return ct;

    }
};