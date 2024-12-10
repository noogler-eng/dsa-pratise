// Maxium Sum Of Non Adjacent Element || House Robber
#include<iostream>
#include<vector>
using namespace std;

// House Robbery
// time complexity o(N)
// space complexity o(N)
int house_robber(vector<int> houses_with_money_stashed){
    vector<int> table(houses_with_money_stashed.size()+1);
    table[0] = 0;
    table[1] = houses_with_money_stashed[0];

    for(int i=2; i<houses_with_money_stashed.size()+1; i++){
        // either i am rooberring it or not
        // if roberry 
        int robbery = table[i-2] + houses_with_money_stashed[i-1];
        // if not robbery
        int no_robbery = table[i-1];
        table[i] = max(robbery, no_robbery);
    }

    return table[houses_with_money_stashed.size()];
}

int main(){
    // there is no codition of circular
    vector<int> houses_with_money_stashed = {1, 2, 3, 1};
    cout<<house_robber(houses_with_money_stashed)<<endl;
    return 0;
}

