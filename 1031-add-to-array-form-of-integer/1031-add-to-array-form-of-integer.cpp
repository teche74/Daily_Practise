class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int>res;
        bool carry = false; 

        for(int i = num.size()  - 1 ; i >= 0 || k > 0 || carry; i--){
            int a = i >= 0 ? num[i] : 0;
            int b = k % 10;
            k/=10;
            int total = a + b + (carry  ? 1 : 0); 

            carry = total > 9 ? true : false;

            res.push_back(total % 10);
        }

        reverse(res.begin() , res.end());

        return res;
    }
};