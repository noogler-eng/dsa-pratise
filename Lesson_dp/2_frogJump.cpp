// Frog Jump

#include<iostream>
#include<vector>
using namespace std;
int min_energy_used(vector<int> energy_stairs){
    vector<int> table(energy_stairs.size()+1);
    table[0] = 0;

    for(int i=1; i<energy_stairs.size()+1; i++){
        // comming from 1 stair behind
        int energy1 = table[i-1] + energy_stairs[i-1] - energy_stairs[i-2];
        // comming from 2 stair behind
        int energy2 = table[i-2] + energy_stairs[i-1] - energy_stairs[i-3];
        table[i] = min(energy1, energy2);
    }
    return table[energy_stairs.size()];
}

int main(){
    vector<int> arr = {10, 20, 30, 10};
    cout<<min_energy_used(arr)<<endl;
    return 0;
}