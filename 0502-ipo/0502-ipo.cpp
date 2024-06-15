class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int size = profits.size();

        vector<pair<int,int>>projects;

        for(int ind =0;ind < size; ind++){
            projects.emplace_back(capital[ind],profits[ind]);
        }

        sort(projects.begin(),projects.end());

        priority_queue<int>pq;

        int ind = 0;

        while(k--){
            while(ind < size && projects[ind].first <= w){
                pq.push(projects[ind].second);
                ind++;
            }

            if(pq.empty()) break;

            w+=pq.top();
            pq.pop();
        }

        return w;
    }
};