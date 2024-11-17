// QUESTION LINK : https://leetcode.com/contest/weekly-contest-274/problems/number-of-laser-beams-in-a-bank/


#include<iostream>
#include<vector>
using namespace std;

// 0 means empty cell
// 1 means laserd cell
// one laser beam between any two security devices
// {"011001","000000","010100","001000"}
// {3, 0, 2, 1}
// time complexity o(N * N)
// space compelxity o(N)
int no_of_beam(vector<string> bank){
    vector<int> no_of_device(bank.size());
    for(int i=0; i<bank.size(); i++){
        int countNoOfDevice = 0;
        for(int j=0; j<bank[i].size(); j++){
            if(bank[i][j] == '1') countNoOfDevice++;
        }
        no_of_device[i] = countNoOfDevice;
    }
    
    // no of lasers
    int i = 0, j = 0, count = 0;
    while(i < no_of_device.size() && j < no_of_device.size()){
        if(no_of_device[i] == 0){
            i++;
            j++;
            continue;
        }

        if(j == i || no_of_device[j] == 0) {
            j++;
            continue;
        }

        count+=no_of_device[i]*no_of_device[j];
        i = j;
        j++;
    }
    return count;
}


int main(){
    vector<string> bank = {"011001","000000","010100","001000"};
    cout<<no_of_beam(bank)<<endl;
    return 0;
}