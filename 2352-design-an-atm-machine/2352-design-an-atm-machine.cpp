class ATM {
public:
    unordered_map<int, long long> map;
    vector<int> amounts = {20,50,100,200,500};

    ATM() {
        for (int denom : amounts) {
            map[denom] = 0;
        }
    }
    
    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < banknotesCount.size(); i++) {
            map[amounts[i]] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        if (amount % 10 != 0) return {-1};
        vector<int> res(amounts.size(), 0);
        unordered_map<int, long long> temp = map;
        int size = amounts.size();

        for (int i = size-1; i >=0 ; i--) {
            int denom = amounts[i];
            int count = min(amount / denom, static_cast<int>(temp[denom]));
            amount -= count * denom;
            temp[denom] -= count;
            res[i] = count;
        }

        if (amount == 0) {
            map = temp;
            return res;
        }
        return {-1};
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
