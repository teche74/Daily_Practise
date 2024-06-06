#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

class Solution {
public:
    bool isNStraightHand(std::vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        unordered_map<int, int> map;
        for (int card : hand) {
            map[card]++;
        }

        vector<int> temp;
        for (const auto& entry : map) {
            temp.push_back(entry.first);
        }
        sort(temp.begin(), temp.end());

        for (int card : temp) {
            int freq = map[card];
            if (freq > 0) {
                for (int i = 0; i < groupSize; ++i) {
                    int nextCard = card + i;
                    
                    if (map[nextCard] < freq) {
                        return false; 
                    }
                    map[nextCard] -= freq;
                }
            }
        }

        return true;
    }
};
