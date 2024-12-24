// QUESTION - https://leetcode.com/problems/car-fleet/

#include<iostream>
using namespace std;

// time complexity o(NlogN)
// space complexity o(2N)
// time should be in double as ans changes by points also
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> position_with_time(n);
        for(int i=0; i<n; i++){
            int dist = target - position[i];
            double time = double(dist)/double(speed[i]);
            position_with_time[i] = {dist, time};
        }

        sort(position_with_time.begin(), position_with_time.end(), [](pair<int, double> &x, pair<int, double> &y){
            return x.first < y.first;
        });

        int count = 0;
        double lastTime = 0;
        for(int i=0; i<n; i++){
            if(position_with_time[i].second > lastTime){
                count+=1;
                lastTime = position_with_time[i].second;
            }
        }

        return count;
    }
};