// QUESTION - https://leetcode.com/problems/house-robber-ii/
// House Robber - 2 

#include<iostream>
#include<vector>
using namespace std;

// House Robbery
// time complexity o(2N)
// space complexity o(2N)
int house_robber_2(vector<int> houses_with_money_stashed){
    vector<int> table(houses_with_money_stashed.size() + 1);
    table[0] = 0;
    table[1] = houses_with_money_stashed[0];

    for (int i = 2; i < houses_with_money_stashed.size() + 1; i++) {
        // if roberry
        int robbery = table[i - 2] + houses_with_money_stashed[i - 1];
        // if not robbery
        int no_robbery = table[i - 1];
        table[i] = max(robbery, no_robbery);
    }

    return table[houses_with_money_stashed.size()];
}

int main(){
    // there is condition of circular
    vector<int> houses_with_money_stashed = {2, 3, 2, 1};

    if(houses_with_money_stashed.size() == 1) return houses_with_money_stashed[0];
    vector<int> temp1, temp2;
    
    for(int i=0; i<houses_with_money_stashed.size()-1; i++) temp1.push_back(houses_with_money_stashed[i]);
    for(int i=1; i<houses_with_money_stashed.size(); i++) temp2.push_back(houses_with_money_stashed[i]);
    int ans = max(house_robber_2(temp1), house_robber_2(temp2));
    cout<<ans<<endl;
    return 0;
}

