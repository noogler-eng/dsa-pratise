// QUESTION - https://www.naukri.com/code360/problems/ninja-s-training_3621003?leftPanelTabValue=SUBMISSION

#include<iostream>
#include<vector>
using namespace std;

// we have to select one training at each day
// we can't do the same training continously
// time complexity o(N)
// space complexity o(N*N)
int ninjas_training(vector<vector<int>> training_points){
    vector<vector<int>> table(training_points.size() + 1, vector<int>(4));
    for(int i=0; i<4; i++) table[0][i] = 0;
    
    for(int i=1; i<training_points.size()+1; i++){
        table[i][0] = training_points[i-1][0] + max(table[i-1][1], table[i-1][2]);
        table[i][1] = training_points[i-1][1] + max(table[i-1][0], table[i-1][2]);
        table[i][2] = training_points[i-1][2] + max(table[i-1][0], table[i-1][1]);

        table[i][3] = max(max(table[i][0], table[i][1]), table[i][2]);
    }
    return table[training_points.size()][3];
}


int main(){
    vector<vector<int>> training_points = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}};
    cout<<ninjas_training(training_points)<<endl;
    return 0;
}