// QUESTION LINK- https://leetcode.com/problems/destroying-asteroids/

#include<iostream>
#include<vector>
using namespace std;


// sort vector - {3, 5, 9, 19, 21}
// attack to mass - 13, 18, 27, 46 .... returnt true
// sort vector - {4, 4, 9, 23}
// attack to mass - 9, 13, 22 .... return false
// time complexity o(NlogN)
// space complexity o(1)
bool is_all_aestorid_destroyed(vector<int> aestroids, int mass){
    sort(aestroids.begin(), aestroids.end());
    // mass can be bigger so long long int
    long long int planet_mass = mass;
    for (int i = 0; i < aestroids.size(); i++) {
        if (aestroids[i] <= planet_mass) planet_mass += aestroids[i];
        else return false;
    }
    return true;
}

int main(){
    vector<int> aestroids = {3,9,19,5,21};
    int mass = 10;
    cout<<is_all_aestorid_destroyed(aestroids, mass)<<endl;
    return 0;
}