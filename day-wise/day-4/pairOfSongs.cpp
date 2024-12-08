// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

// time complexity o(N*N)
// space complexity o(1)

int no_of_pair_durations_divisible_by_60(vector<int> time){
    int count = 0;
    for(int i=0; i<time.size(); i++){
        for(int j=i+1; j<time.size(); j++){
            if((time[i] + time[j]) % 60 == 0 ) count++;
        }
    }
    return count;
}

// {30,20,150,100,40}
// 30, 20, 150, 100
int no_of_pair_durations_divisible_by_60_o(vector<int> time){
    int count = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < time.size(); i++) {
        if (m.find((60 - (time[i] % 60)) % 60) != m.end()) count+=m[(60 - (time[i] % 60)) % 60];
        m[time[i] % 60]++;
    }
    return count;
}


int main(){
    vector<int> time = {30,20,150,100,40};
    cout<<no_of_pair_durations_divisible_by_60(time)<<endl;
    cout<<no_of_pair_durations_divisible_by_60_o(time)<<endl;
    return 0;
}