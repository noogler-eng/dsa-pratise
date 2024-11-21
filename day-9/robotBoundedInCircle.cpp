// Question - https://leetcode.com/problems/robot-bounded-in-circle/description/

#include<iostream>
#include<vector>
using namespace std;

// time complexity o(N)
// space complexity o(N)
bool is_robot_bounded(string inst) {
    int current_x = 0;
    int current_y = 0;

    // noth east south west;
    vector<pair<int, int>> currentD = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int curr_dir = 0;

    int i = 0;
    while (i < inst.length()) {
        if (inst[i] == 'L') {
            curr_dir = (curr_dir + 3) % 4;
        } else if (inst[i] == 'R') {
            curr_dir = (curr_dir + 1) % 4;
        } else {
            current_x += currentD[curr_dir].first;
            current_y += currentD[curr_dir].second;
        }
        i++;
    }

    if (current_x == 0 && current_y == 0) return true;
    else if (curr_dir == 0) return false;
    else return true;
}

int main(){
    cout<<is_robot_bounded("GLRLLGLL");
    return 0;
}