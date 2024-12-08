// codeforces
// connecting graphs

// roads we have to be taken, road between the nodes having same parent
// node to join which are having different parent

#include<iostream>
#include<set>
#include<vector>
using namespace std;

class DSU {
    public:
    vector<int> parent, size;
    DSU(int n){
        for(int i=0; i<n; i++){
            parent.push_back(i);
            size.push_back(1);
        }
    }

    void join_parent(int node1, int node2){
        if(parent[node1] == parent[node2]) return;
        else{
            if(size[node1] > size[node2]){
                size[node1] += size[node2];
                parent[node2] = node1;
            }else{
                size[node2] += size[node1];
                parent[node1] = node2;
            }
        }
    }

    int find_parent(int node){
        if(parent[node] == node) return node;
        return parent[node] = find_parent(node);
    }
};

void roadsInBerland(int n, int m){
    // takin here the u and v from the input
    vector<pair<int, int>> extraRoad;
    DSU dsu(n+1);

    for(int i=0; i<m; i++){
        int u, v;
        // step1 - storage of old road is done;
        if(dsu.find_parent(u) == dsu.find_parent(v)){
            extraRoad.push_back({u, v});
        }else{
            dsu.join_parent(u, v);
        }

        // step2 - figure out the number of components
        set<int> st;
        for(int i=0; i<n+1; i++){
            st.insert(dsu.find_parent(i));
        }


        int no_of_islands = st.size();
        int no_of_roads_required = no_of_islands - 1;
        // step3 -  

        vector<int> vec(st.begin(), st.end());
        int j = 0;
        for(int i=1; i<=no_of_islands; i++){
            cout<<extraRoad[j].first<<"connected to "<<extraRoad[j].second<<vec[i]<<" "<<vec[i-1]<<endl;
            j++;
        }
    }
}