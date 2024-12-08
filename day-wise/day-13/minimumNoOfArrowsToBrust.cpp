// QUESTION LINK: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/ 

#include<iostream>
#include<vector>
using namespace std;

// important question
// time compleixty o(NlogN + N)
// sapce complexity o(1)
int minimum_of_array_to_brust_all(vector<vector<int>> ballons_dia){
    sort(ballons_dia.begin(), ballons_dia.end(), [](vector<int> &x, vector<int> &y){
        if(x[1] == y[1]) return x[0] < y[0];
        else return x[1] < y[1];
    });

    int count = 1, end_point = ballons_dia[0][1];
    // keeping the endpoint in common is same until last
    for(int i = 1; i < ballons_dia.size(); i++){
        if(ballons_dia[i][0] < end_point) continue;
        count++;
        end_point = ballons_dia[i][1];
    }
    return count;

}

int main(){
    vector<vector<int>> ballons_dia = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    cout<<minimum_of_array_to_brust_all(ballons_dia)<<endl;
    return 0;
}   