// QUESTION - https://leetcode.com/problems/maximum-area-rectangle-with-point-constraints-i/
// Max area of reactangle in which no other points lie inside
#include<iostream>
#include<vector>
using namespace std;

int area_react(vector<vector<int>> points){
    vector<int> bl, br, tl, tr;
    bl = points[0];
    tl = points[1];
    br = points[2];
    tr = points[3];

    if(bl[0] != tl[0] || br[0] != tr[0] || bl[1]!=br[1] || tl[1]!=tr[1]) return -1;
    return abs((tl[1] - bl[1])*(br[0]-bl[0]));
}

bool hasBetweenPoints(vector<vector<int>> selected_points, vector<vector<int>> points){
    vector<int> bl, br, tl, tr;
    bl = selected_points[0];
    tl = selected_points[1];
    br = selected_points[2];
    tr = selected_points[3];

    for(auto it: points){
        if(it != bl && it!=br && it!= tl && it!=tr){
            if(it[0] >= bl[0] && it[0] <=  br[0] && it[1] >= bl[1] && it[1] <= tr[1]){
                return true;
            }
        }
    }
    return false;
}

int max_area(vector<vector<int>> &points){
    int ans = -1;
    int n = points.size();
    if(n < 4) return 0;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                for(int l=k+1; l<n; l++){
                    vector<vector<int>> selected_points = {points[i], points[j], points[k], points[l]};
                    // on the basis of x they will be sorted
                    sort(selected_points.begin(), selected_points.end());
                    int area = area_react(selected_points);
                    if(area == -1) continue;
                    if(hasBetweenPoints(selected_points, points)) continue;
                    ans = max(ans, area);
                }
            }
        }
    }
    return ans;
}