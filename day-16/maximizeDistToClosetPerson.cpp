// QUESTION LINK: https://leetcode.com/problems/maximize-distance-to-closest-person/

#include<iostream>
#include<vector>
using namespace std;

// brute force approach
// time complexity o(N)
// space complexity o(2N)
// 1, 0, 0, 0, 1, 0, 1
int maximize_distance_to_closet_person(vector<int> seats){
    // simpley storing the recent 1 from left and from right
    vector<int> right_most_indexes(seats.size());
    vector<int> left_most_indexes(seats.size());

    // from left
    int from_left = INT_MAX;
    for (int i = 0; i < seats.size(); i++) {
        left_most_indexes[i] = from_left;
        if (seats[i] == 1)
            from_left = i;
    }

    // from right
    int from_right = INT_MAX;
    for (int i = seats.size() - 1; i >= 0; i--) {
        right_most_indexes[i] = from_right;
        if (seats[i] == 1)
            from_right = i;
    }

    int ans = 1;
    for (int i = 0; i < seats.size(); i++)
        if(seats[i] == 0) ans = max(ans, min(abs(i - left_most_indexes[i]), abs(right_most_indexes[i] - i)));
    return ans;
}

// time complexity o(N)
// space complexity o(1)
// most optmial approach
// we are placing in between the digit so in this we are not adding 1 as 1 distance will be reduce so 
// they fitus each other
int maximize_distance_to_closet_person_o(vector<int> seats){
    // here we are mainly focuses on distance between exisitng 1's
    int i = 0;
    int recent_left_1 = -1;
    int maxi = -1;
    while(i < seats.size()){
        if(seats[i] == 1){
            if(recent_left_1 == -1) maxi = i - recent_left_1;
            else {
                maxi = max(maxi, ((i-recent_left_1)/2)+1);
            }
            recent_left_1 = i;
        }
        i++;
    }

    int n = seats.size()-1;
    if(seats[n] == 0) maxi = max(n-recent_left_1, maxi);
    return maxi;
}

int main(){
    vector<int> seats = {1, 0, 0, 0, 1, 0, 1};
    cout<<maximize_distance_to_closet_person(seats)<<endl;
    cout<<maximize_distance_to_closet_person_o(seats)<<endl;
    return 0;
}