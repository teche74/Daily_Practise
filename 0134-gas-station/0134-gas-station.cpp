class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // int res = -1;

        // int size = gas.size();

        // for(int i = 0 ;  i < size; i ++){
        //     int take =  gas[i];
        //     // cout<<"Start kiya "<<i<<" se"<<endl;

        //     for(int j = i+1; j <= i + size; j++ ){

        //         if(cost[(j-1) % size] > take){
        //             // cout<<"not_possible"<<endl;
        //             break;
        //         }
        //         take -=cost[(j-1) % size];
        //         // cout<<j %size<<" jane ke liye cost lga "<<cost[(j-1) % size]<<endl;
        //         take+=gas[j % size];
        //         // cout<<"gas bhra "<<gas[j % size]<<endl;

        //         if(take <= 0){
        //             // cout<<"not possible"<<endl;
        //             break;
        //         }

        //         if(j % size == i){
        //             // cout<<"Suru kr skten hen index "<<i<<" se"<<endl;
        //             res =  i;
        //             break;
        //         }
        //     } 

        //     if(res != -1) break;
        // }
        // return res;


        int size = gas.size();

        vector<int> easy;

        for(int i = 0; i <size ; i++){
            easy.emplace_back(gas[i] - cost[i]);
        }

        int total = 0 , curr = 0, start = 0;

        for(int i = 0; i< size; i++){
            total += easy[i];
            curr += easy[i];

            if(curr < 0){
                start = i+1;
                curr= 0 ;
            }
        }

        return total >= 0 ? start : -1; 
    }
};