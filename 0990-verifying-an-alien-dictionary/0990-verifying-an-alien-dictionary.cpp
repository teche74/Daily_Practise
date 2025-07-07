class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int size = words.size();
        unordered_map<char,int>index;

        for(int i = 0 ; i < order.size() ; i++){
            index[order[i]] = i;
        }

        for(int i =1; i < size; i++){
            string str = words[i-1] , ptr =words[i];
            bool cond = false;

            for(int j = 0; j < min(str.size()  , ptr.size()) ; j++){
                if (index[str[j]] < index[ptr[j]]) {
                    cond = true;
                    break;
                } else if (index[str[j]] > index[ptr[j]]) {
                    return false;
                }
            }

            if (!cond && str.size() > ptr.size()) {
                return false;
            }
        }

        return true;
    }
};