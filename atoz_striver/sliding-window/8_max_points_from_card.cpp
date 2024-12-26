// Maximum point you can obtain from cards
// QUESTION - https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/

#include<iostream>
#include<vector>
using namespace std;

// time complexity o(2K)
// space complexity o(1);
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        for(int i=0; i<k; i++) sum+=cardPoints[i];

        int i=0;
        int maxPoints = sum;
        while(k > 0){
            sum-=cardPoints[k-1];
            sum+=cardPoints[cardPoints.size()-1-i];
            maxPoints = max(maxPoints, sum);
            k--;
            i++;
        }
        return maxPoints;
    }
};