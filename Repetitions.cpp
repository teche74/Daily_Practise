#include<bits/stdc++.h>
using namespace std;


int main(){
    string str;
    unordered_map<char,int>map;

    while(cin >> str){
        int low = 0, high = 0 , size = str.size(), index = -1, len = 1;
        map.clear();

        while(high < size){
            map[str[high]]++;

            while(map.size() > 1){
                map[str[low]]--;
                if(map[str[low]] == 0){
                    map.erase(str[low]);
                }
                low++;
            }
            
            if(high - low + 1 > len){
                index = low;
                len = high - low + 1;
            }
            high++;
        }


        cout<<len<<endl;
    }

    return 0;
}