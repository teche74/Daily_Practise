class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>temp;
        int size = s.size();

        function<bool(int,int)> __palli = [&](int low, int high)->bool{
            while(low <= high){
                if(s[low] != s[high]) return false;
                low++,high--;
            }

            return true;
        };

        function<void(int)> call = [&](int index){
            if(index >= size){
                res.push_back(temp);
                return;
            }

            for(int i = index; i < size; i++){
                if(__palli(index, i)){
                    temp.push_back(s.substr(index , i - index+1));
                    call(i+1);
                    temp.pop_back();
                }
            }
        };

        call(0);

        return res;
    }
};