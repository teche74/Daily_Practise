class DisjointSet{
    private:
    vector<int>parent, unionbysize;

    public:

    DisjointSet(int size){
        parent.resize(size+1);
        unionbysize.resize(size+1);

        for(int i = 0 ; i <= size ; i++){
            parent[i] = i;
            unionbysize[i] = 1;
        }
    }


    int find_parent(int node){
        if(parent[node] != node){
            parent[node] = find_parent(parent[node]); 
        }
        return parent[node];
    }

    void do_union(int node1 , int node2){
        int parent_node1 = find_parent(node1);
        int parent_node2 = find_parent(node2);

        if(parent_node1 != parent_node2){
            if(unionbysize[parent_node1] > unionbysize[parent_node2]){
                parent[parent_node2] = parent_node1;
                unionbysize[parent_node1] += unionbysize[parent_node2];
            }
            else{
                parent[parent_node1] = parent_node2;
                unionbysize[parent_node2] += unionbysize[parent_node1];
            }
        }
    }
};

class Solution {
public:
    int calc_distance(int x1 , int y1 , int x2 , int y2){
        return abs(x1 -x2) + abs(y1 - y2); 
    }

    int Krush( vector<pair<int,pair<int,int>>> & edges , int size){
        DisjointSet ds(size);

        sort(edges.begin(), edges.end() , [&](pair<int,pair<int,int>>& a , pair<int,pair<int,int>> &b){
            return a.first < b.first;
        });

        int total_distance = 0;

        for(auto t : edges){
            int dist = t.first;
            int node1 = t.second.first;
            int node2 = t.second.second;

            if(ds.find_parent(node1) != ds.find_parent(node2)){
                total_distance += dist;
                ds.do_union(node1 , node2);
            }
        }

        return total_distance;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        //  so first we have to calulate distance of points.

        vector<pair<int,pair<int,int>>>edges;
        
        int size = points.size();

        for(int i  =0 ; i < size; i++){
            for(int j = 0; j < size ; j++){
                if(i != j){
                    int dist = calc_distance(points[i][0] , points[i][1] , points[j][0] , points[j][1]);
                    edges.push_back({dist,{i , j}});
                }
            }
        }

        return Krush(edges,size);
    }
};