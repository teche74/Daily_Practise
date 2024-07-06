class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>>adj;

        for(auto t : tickets){
            adj[t[0]].insert(t[1]);
        }

        // heir - holzers algorithm use ki he.

        vector<string>path;
        stack<string>st;
        st.push("JFK");

        while(st.size()){
            string curr = st.top();

            if(adj[curr].empty()){
                path.emplace_back(curr);
                st.pop();
            }
            else{
                st.push(*adj[curr].begin());
                adj[curr].erase(adj[curr].begin());
            }
        }

        reverse(path.begin(),path.end());
        return path;
    }
};