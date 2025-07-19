#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    while (cin >> t) {
        int cards, a, b;
        cin >> cards >> a >> b;

        int equal = cards - a - b;
        if (equal < 0 || a > cards || b > cards) {
            cout << "NO\n";
            continue;
        }

        set<int>all_a , all_b;

        vector<int>a_choice, b_choice;

        for(int i = 1 ; i <= cards ; i++){
            all_a.insert(i);
            all_b.insert(i);
        }

        int remain = a;

        while(remain--){
            int value1 = *all_a.rbegin();
            int value2 = value1-1;
            all_a.erase(value1);
            all_b.erase(value2);

            a_choice.push_back(value1);
            b_choice.push_back(value2);
        }

        remain = b;

        while(remain--){
            int value1 = *all_b.rbegin();
            int value2 = value1-1;
            all_b.erase(value1);
            all_a.erase(value2);

            b_choice.push_back(value1);
            a_choice.push_back(value2);
        }

        while(all_a.size()){
            int value = *all_a.begin();

            all_a.erase(value);
            all_b.erase(value);

            b_choice.push_back(value);
            a_choice.push_back(value);
        }



        cout << "YES\n";
        for (int x : a_choice) cout << x << " ";
        cout << "\n";
        for (int x : b_choice) cout << x << " ";
        cout << "\n";
    }
}
