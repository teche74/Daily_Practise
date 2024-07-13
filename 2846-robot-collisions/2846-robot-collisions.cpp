class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& heal, string dir) {
        int size = pos.size();

        vector<int>ind , res;

        stack<int>st;

        for(int i = 0 ;i < size ; i++ ){
            ind.emplace_back(i);
        }


        sort(ind.begin(), ind.end() , [&](int x, int y){
            return pos[x] < pos[y];
        });

        for(int x :  ind){
            if(dir[x] == 'R'){
                st.push(x);
            }
            else
            {
                while(!st.empty() && heal[x] > 0){
                    int top = st.top();
                    st.pop();

                    if(heal[top] > heal[x]){
                        heal[top] -= 1;
                        heal[x] = 0;
                        st.push(top);
                    }
                    else if(heal[top] < heal[x]){
                        heal[x] -= 1;
                        heal[top] = 0;
                    }
                    else{
                        heal[x] = 0 ;
                        heal[top] = 0;
                    }
                }
            }
        }

        for(int i = 0; i<size ; i++){
            if(heal[i] > 0){
                res.push_back(heal[i]);
            }
        }
        return res;
    }
};