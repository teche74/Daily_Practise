class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& custs) {
        double total_time = 0;
        int prev_finish = 0;

        for (const auto& cust : custs) {
            int arrival = cust[0];
            int time_needed = cust[1];

            int start_time = max(arrival, prev_finish);
            int finish_time = start_time + time_needed;
            int waiting_time = finish_time - arrival;

            total_time += waiting_time;
            prev_finish = finish_time;
        }

        return total_time / custs.size();
    }
};
