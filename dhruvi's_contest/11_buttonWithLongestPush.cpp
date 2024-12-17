// QUESTION - https://leetcode.com/contest/weekly-contest-428/submissions/detail/1479006456/
#include<iostream>
#include<vector>
using namespace std;

// time complexity O(N)
// space complexity O(1)
class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int longest_time = events[0][1];
        int longest_time_button = events[0][0];
        int prev_time = 0;
        
        for(int i = 1; i < (int)events.size(); ++i){
            int time = events[i][1] - events[i - 1][1];
            int button = events[i][0];
            
            if(time > longest_time){
                longest_time = time;
                longest_time_button = button;
            }
            else if(time == longest_time){
                if((longest_time_button == -1) || (button < longest_time_button)){
                    longest_time_button = button;
                }
            }
        }
        return longest_time_button;
    }
};