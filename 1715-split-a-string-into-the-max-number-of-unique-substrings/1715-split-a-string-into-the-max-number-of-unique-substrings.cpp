class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_map<string,int>seen;
        int size = s.size();

        function<int(int)> solve = [&](int index){
            if(index >= size){
                return 0;
            }

            int count = 0;

            for(int i = index; i < size ; i++){
                string ptr = s.substr(index , i - index +1);
                if(seen.find(ptr) == seen.end()){
                    seen[ptr]++;
                    count = max(count , 1 + solve(i+1));
                    seen.erase(ptr);
                }
            }

            return count;
        };


        return solve(0);

    }
};