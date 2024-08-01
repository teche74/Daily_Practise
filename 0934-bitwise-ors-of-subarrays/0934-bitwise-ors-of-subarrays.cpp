class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>st;

        int size = arr.size();

        int curr = 0;

        for(int i = 0; i < size ; i++){
            curr |= arr[i];

            int prev = 0;
            for(int j = i ; j >= 0 ;j -- ){
                prev |= arr[j];

                st.insert(prev);

                if(prev == curr){
                    break;
                }
            }
        }
        return st.size();
    }
};