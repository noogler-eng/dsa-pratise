// QUESTION LINK: https://leetcode.com/problems/assign-cookies/description/

#include<iostream>
#include<vector>
using namespace std;


// time complexity o(2*NlogN)
// space complexity o(1)
int fin_content_children(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i = 0, j = 0;
    while(i < s.size() && j < g.size()){
        if(s[i] >= g[j]) j++;
        i++;
    }
    return j;
}

int main(){
    vector<int> children = {1, 2, 3};
    vector<int> cookies = {1, 1};
    cout<<fin_content_children(children, cookies)<<endl;
    return 0;
}