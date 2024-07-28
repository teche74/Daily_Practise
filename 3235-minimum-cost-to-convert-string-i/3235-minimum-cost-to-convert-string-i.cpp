class Solution {    
public:
    vector<vector<pair<int, int>>> graph;
    const int INF = 1000000000;
    int dist[26][26];
    void floydWarshall() {
      for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph[i].size(); j++) {
          dist[i][graph[i][j].first] = min(graph[i][j].second , dist[i][graph[i][j].first]);
        }
      }

      for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
          for (int j = 0; j < 26; j++) {
            if ((dist[i][j] > (dist[i][k] + dist[k][j])) && (dist[k][j] != INF && dist[i][k] != INF))
                        dist[i][j] = dist[i][k] + dist[k][j];
          }
        }
      }
    }
    
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        graph.resize(26);
        int n = original.size();
        for(int i = 0; i < 26; i++) 
            for(int j = 0; j < 26; j++) dist[i][j] = INF;
        
        for(int i = 0; i < n; i++) {
            graph[original[i] - 'a'].push_back({changed[i] - 'a' , cost[i]});
            dist[original[i] - 'a'][changed[i] - 'a'] = cost[i];
        }    
        
        
        floydWarshall();
        
        long long ans = 0;
        for(int i= 0 ; i < source.size(); i++) {
            if(source[i] ==  target[i] ) continue;
            int temp = dist[source[i] - 'a'][target[i] - 'a'];
            if(temp == INF) return -1;
            ans += dist[source[i] - 'a'][target[i] - 'a'];
        }
        return ans;
        
    }
};