#include <bits/stdc++.h>
using namespace std;


int main()
{
    string inp;
    
    while (cin >> inp)
    {
        unordered_map<char,int>map;
        int count_uni = 0;
        for(char ch : inp){
            map[ch]++;
        }

        
        string res = string(inp.size() , '.');
        int low = 0, high = inp.size()-1;
        
        for(auto &t : map){
            if(t.second > 1){
                int occur =t.second / 2;
                
                while(occur--){
                    t.second -= 2;
                    res[low] = t.first;
                    res[high] = t.first;
                    low++, high--;
                }
            }

            count_uni += (t.second % 2);
        }

        if(count_uni > 1){
            cout<<"NO SOLUTION"<<endl;
            continue;
        }
        
        if(count_uni == 1){
            for(auto t : map){
                if(t.second == 1){
                    res[low] = t.first;
                }
            }
        }

        cout<<res<<endl;
    }
    return 0;
}
