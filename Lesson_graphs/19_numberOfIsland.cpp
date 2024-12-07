// QUESTION - https://leetcode.com/problems/number-of-islands-ii/description/
// Number of Island 

#include<iostream>
using namespace std;

class DSU{
    public:
    vector<int> parent, size;
    DSU(int n){
        for(int i=0; i<n; i++){
            parent.push_back(i);
            size.push_back(1);
        }
    }

    int find_parent(int node){
        if(parent[node] == node) return node;
        return parent[node] = find_parent(node);
    }

    void join_land(int node1, int node2){
        if(parent[node1] == parent[node2]){
            return;
        }else{
            if(size[node1] > size[node2]){
                parent[node2] = parent[node1];
                size[node1] += size[node2];
            }else{
                parent[node1] = parent[node2];
                size[node2] += size[node1];
            }
        }
    }
};

vector<int> connecting_island(int m, int n, vector<vector<int>> ops){
    vector<int> ans;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    DSU dsu(m*n);
    int noOfIsland = 0;

    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};
    for(int j=0; j<ops.size(); j++){
        int x = ops[j][0];
        int y = ops[j][1];

        if (mat[x][y] == 1) {
            ans.push_back(noOfIsland);
            continue;
        }

        mat[x][y] = 1;
        noOfIsland++;

        int index = x * m + y;

        for(int i=0; i<4; i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            
            if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && mat[new_x][new_y] == 1){
                int new_index = new_x * m + new_y;

                if(dsu.find_parent(index) != dsu.find_parent(new_index)) {
                    noOfIsland--;
                    dsu.join_land(index, new_index);
                }
            }
        }
        ans.push_back(noOfIsland);
    }
    return ans;
}