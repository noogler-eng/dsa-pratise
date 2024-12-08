// QUESTION LINK: https://leetcode.com/problems/intersection-of-two-arrays-ii/

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

// brute force
// time complexity o(N*N)
// space complexity o(1)
vector<int> get_array_of_intersection(vector<int> x, vector<int> y){
    vector<int> temp;
    for(int i=0; i<x.size(); i++){
        for(int j = 0; j<y.size(); j++){
            if(x[i] == y[j]){
                temp.push_back(x[i]);
                // so same elelemt of y does't count again and again
                y[j] = INT_MIN;
                break;
            }
        }
    }
    return temp;
}

// optmised approach
// time complexity o(N)
// space compleity o(N)
vector<int> get_array_of_intersection_o(vector<int> x, vector<int> y){
    unordered_map<int, int> m;
    vector<int> temp;
    for(int i=0; i<x.size(); i++) m[x[i]]++;
    for(int j=0; j<y.size(); j++){
        if(m.find(y[j]) != m.end()){
            temp.push_back(y[j]);
            m[y[j]]--;
            if(m[y[j]] == 0) m.erase(y[j]);
        }
    }
    return temp;
}



void print(vector<int> x){
    for(auto i: x) cout<<i<<" ";
    cout<<endl;
}

int main(){
    vector<int> x = {1, 2, 2, 1};
    vector<int> y = {2, 2};
    vector<int> ans = get_array_of_intersection(x, y);
    vector<int> ans1 = get_array_of_intersection_o(x,y);
    print(ans);
    print(ans1);
    return 0;
}