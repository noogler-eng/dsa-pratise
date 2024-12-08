#include<iostream>
#include<vector>
using namespace std;

// import ant hard level question
// time complexity o(N*N)
// space complexity o(N)
// we are looking for if alice win at that stage now bob can also win at that
// if alice fails then bob can also
int stoneGame4(int n){
    vector<bool> dp(n+1,false);
    dp[1] = true;
    for(int i=2;i<= n;i++){
        for(int j = 1;j * j <= i;j++){
            if(!dp[i-(j*j)]){
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}
