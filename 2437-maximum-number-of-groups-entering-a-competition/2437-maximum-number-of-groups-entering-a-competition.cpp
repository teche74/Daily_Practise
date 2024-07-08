class Solution {
public:
    bool Check(vector<int>& arr, long long max_size) {
        long long prev_sum = INT_MAX, prev_ele = INT_MAX;
        long long  size = arr.size(), sum = 0 , ele = 0;

        for(int i = 0; i < size ; i ++){
            sum+=arr[i];
            ele++;

            if(ele == max_size){
                // cout<<"sum : "<<sum<<" ele :"<<ele<<endl;
                // cout<<"prev sum : "<<prev_sum<<"prev ele :"<<prev_ele<<endl;
                
                if(prev_sum <= sum  || prev_ele <= ele) return false;


                prev_sum = sum;
                prev_ele = ele;
                sum = 0 ,ele = 0;
                max_size--;
            }
        }

        return max_size == 0;
    }

    int maximumGroups(vector<int>& grades) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        long long low = 1, high = grades.size() < 3 ? grades.size() : grades.size()/2;

        sort(grades.rbegin(), grades.rend());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (Check(grades, mid)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }
};
