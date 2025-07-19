#include<bits/stdc++.h>
using namespace std;

int main(){
    int children_count , max_weight;

    while(cin >> children_count >> max_weight){
        vector<int>weights(children_count , 0);

        for(int i = 0 ; i < children_count ;i++){
            cin >> weights[i];
        }


        sort(weights.begin() , weights.end());

        int low = 0, high = children_count-1 , gondolas = 0;

        while(low <= high){
            if(weights[high] + weights[low] <= max_weight){
                low++, high--;
                gondolas++;
            }
            else{
                high--;
                gondolas++;
            }
        }

        cout<<gondolas<<endl;
    }
    return 0;
}