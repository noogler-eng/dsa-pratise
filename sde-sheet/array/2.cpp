// QUESTION - https://leetcode.com/problems/pascals-triangle/

#include<iostream>
#include<vector>
using namespace std;
// appliying the formula
// time complexity o(M*N) + O(N)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0; i<numRows; i++){
            vector<int> miniAns;
            for(int j=0; j<i+1; j++){
                int number = 1;
                for(int k = 0; k < j; k++){
                    number = number * (i - k);
                    number = number / (k+1);
                }
                miniAns.push_back(number);
            }
            ans.push_back(miniAns);
        }
        return ans;
    }
};