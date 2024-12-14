// QUESTION - https://leetcode.com/problems/merge-intervals/

#include<iostream>
#include<vector>
using namespace std;

// time complexity o(N)
// space complexity o(N*2)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &x, vector<int> &y){
            return x[0] < y[0];
        });

        vector<vector<int>> ans;

        int end = intervals[0][1];
        int start = intervals[0][0];
        for(int i=1; i<intervals.size(); i++){
            int current_start = intervals[i][0];
            int current_end = intervals[i][1];
            if(current_start <= end){
                if(current_start < start){
                    start = current_start;
                }
                if(current_end > end){
                    end = current_end;
                }
            }else{
                vector<int> m;
                m.push_back(start);
                m.push_back(end);
                ans.push_back(m);
                start = current_start;
                end = current_end;
            }
        }
        vector<int> m;
        m.push_back(start);
        m.push_back(end);
        ans.push_back(m);
        return ans;
    }
};