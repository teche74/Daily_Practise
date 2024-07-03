class Solution {
public:
    bool solve(const string & num , int index, vector<long long > &res){
        if(index == num.size()){
            return res.size() >=3;
        }

        for(int i = index+1 ;i <= num.size() ; i++){
            if (i > index +1 && num[index] == '0') break;


            long long curr;
            try {
                curr = stoll(num.substr(index, i - index));
            } catch (const out_of_range&) {
                break;
            }

            if(res.size() >= 2){
                if(curr != res[res.size()-1] + res[res.size()-2]) continue;
            }

            res.push_back(curr);

            if(solve(num, i, res)) return true;

            res.pop_back();

            if(curr == 0) break;

        }

        return false;
    }

    bool isAdditiveNumber(string num) {
        vector<long long> store;

        return solve(num,0,store);
    }

};