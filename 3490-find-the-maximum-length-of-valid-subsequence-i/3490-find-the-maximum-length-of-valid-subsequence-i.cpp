// i got difficulty in creating solution so i had started with recursive one first; 

// class Solution {
// public:
//     void solve(int index, vector<int>& nums, vector<int>& temp, int& res) {
//         if (index >= nums.size()) {
//             res = max(res, static_cast<int>(temp.size()));
//             return;
//         }

//         if (temp.size() < 2 || (temp.back() + nums[index]) % 2 == (temp[temp.size() - 1] + temp[temp.size() - 2]) % 2) {
//             temp.push_back(nums[index]);
//             solve(index + 1, nums, temp, res);
//             temp.pop_back();
//         }
        
//         solve(index + 1, nums, temp, res);
//     }
    
//     int maximumLength(vector<int>& nums) {
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
//         int size = 0;
//         vector<int> temp;
//         solve(0, nums, temp, size);
//         return size;
//     }
// };

// i got tle


class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int bit = nums[0] % 2, odd{0}, even{0}, both{0};

        for(auto t : nums){
            if(t & 1){
                even++;
            }
            else{
                odd++;
            }

            if(t % 2 ==  bit){
                bit = 1 -bit;
                both++;
            }
        }

        return max(both , max(even,odd));
    }
};
