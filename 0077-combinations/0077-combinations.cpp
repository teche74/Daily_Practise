class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        vector<int>temp;

        function<void(int)> call = [&](int index){
            if(index > n){
                if(temp.size() == k)
                    res.push_back(temp);
                return;
            }

            temp.push_back(index);
            call(index+1);
            temp.pop_back();
            call(index+1);
        };

        for(int i = 1; i <= n ; i++){
            temp.push_back(i);
            call(i+1);
            temp.pop_back();
        }

        return res;
    }
};