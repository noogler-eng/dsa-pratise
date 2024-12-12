// QUESTION - https://leetcode.com/problems/car-fleet/
// nice question ...

#include<iostream>
#include<vector>
using namespace std;

class Car {
    public: 
    int distance;
    float time;
    int speed;
    Car(int distance, int speed){
        this->distance = distance;
        this->speed = speed;
        this->time = ((distance * 1.0) / speed);
    }
};

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car> cars;
        for(int i=0; i<position.size(); i++){
            cars.push_back(Car(target - position[i], speed[i]));
        }

        sort(cars.begin(), cars.end(), [](Car &a, Car &b){
            return a.distance < b.distance;
        });

        int no_of_fleets = 0;
        float prevTime = -1;
        for(int i=0; i<cars.size(); i++){
            if(cars[i].time > prevTime){
                no_of_fleets++;
                prevTime = cars[i].time;
            }
        }

        return no_of_fleets;
    }
};