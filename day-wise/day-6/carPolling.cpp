//QUESTION LINK: https://leetcode.com/problems/car-pooling/

#include<iostream>
#include<vector>
using namespace std;

// {{2,1,5},{3,3,7}}
// num of passenger, from, to
// overlapping concept of events
// time complexity o(2N)
// space complexity o(N)
bool car_pooling(vector<vector<int>> trips, int capacity){
    vector<pair<int, int>> events;
    for(int i=0; i<trips.size(); i++){
        int sTime = trips[i][1];
        int endTime = trips[i][2];
        int passenger = trips[i][0];

        events.push_back({sTime, passenger});
        events.push_back({endTime, -1 * passenger});
    }

    sort(events.begin(), events.end());
    int passengerAtATime = 0;
    for(int i=0; i<events.size(); i++){
        passengerAtATime += events[i].second;
        if(passengerAtATime > capacity) return false;
    }
    return true;
}

int main(){
    vector<vector<int>> trips = {{2,1,5},{3,3,7}};
    int capacity = 4;
    cout<<car_pooling(trips, capacity)<<endl;
    return 0;
}