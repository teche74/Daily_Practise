class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int size = code.size();

        vector<int>res;
        int low , high,sum;
        if(k > 0){
            low = 1 , high = 1 , sum = 0;

            while(res.size() < size){
                sum += code[high % size];

                while(high - low +1  > k){
                    sum -= code[low % size];
                    low++;
                }
                if(high - low + 1 == k || k == 0) res.emplace_back(sum);
                high++;
            }
        }
        else{
            k*=-1;
            k %= size;

            low = size-k , high = size-k, sum = 0;

            while(res.size() < size){
                sum += code[high % size];

                while(high - low + 1  > k){
                    sum -= code[low % size];
                    low++;
                }
                if(high - low + 1 == k) res.emplace_back(sum);
                high++;
            }
        }
        return res;
    }
};