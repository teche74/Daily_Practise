#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct node {
    node* links[2] = {nullptr, nullptr};
    int count = 0;

    void CreateRef(int bit, node* n) {
        links[bit] = n;
    }

    bool CheckRef(int bit) {
        return links[bit] != nullptr;
    }

    node* GetRef(int bit) {
        return links[bit];
    }

    void IncCount(int val) {
        count += val;
    }

    int CheckCount() {
        return count;
    }
};

class Solution {
public:
    node* root = new node();

    int maximumStrongPairXor(vector<int>& nums) {
        int size = nums.size(), res = 0;

        auto insert = [&](int val) {
            node* temp = root;
            for (int i = 31; i >= 0; i--) {
                int bit = (val >> i) & 1;
                if (!temp->CheckRef(bit)) {
                    temp->CreateRef(bit, new node());
                }
                temp = temp->GetRef(bit);
                temp->IncCount(1);
            }
        };

        auto max_xor = [&](int val) {
            node* temp = root;
            int res = 0;
            for (int i = 31; i >= 0; i--) {
                int bit = (val >> i) & 1;
                if (temp->CheckRef(1 - bit)) {
                    res |= (1 << i);
                    temp = temp->GetRef(1 - bit);
                } else {
                    temp = temp->GetRef(bit);
                }
            }
            return res;
        };

        auto remove = [&](int num) {
            node* temp = root;
            for (int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;
                if (temp->CheckRef(bit)) {
                    node* nextNode = temp->GetRef(bit);
                    nextNode->IncCount(-1);
                    if (nextNode->CheckCount() == 0) {
                        delete nextNode;
                        temp->links[bit] = nullptr;
                        break;  
                    }
                    temp = nextNode;
                }
            }
        };

        sort(nums.begin(), nums.end());

        int low = 0;

        for (int i = 0; i < size; i++) {
            insert(nums[i]);

            while (low < i && abs(nums[i] - nums[low]) > min(nums[i], nums[low])) {
                remove(nums[low++]);
            }

            res = max(res, max_xor(nums[i]));
        }

        return res;
    }
};
