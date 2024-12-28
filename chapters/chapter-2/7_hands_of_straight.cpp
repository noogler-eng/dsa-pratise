// Hands Of Straight
// QUESTION - https://leetcode.com/problems/hand-of-straights/
// nice question

#include<iostream>
#include<map>
#include<vector>
using namespace std;

// Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
// Output: true
// Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]

// Input: hand = [1,2,3,4,5], groupSize = 4
// Output: false
// Explanation: Alice's hand can not be rearranged into groups of 4.

// In the worst case we going to all the elements once
// time complexity o(N+N)
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;
        map<int, int> m;
        for(int i=0; i<hand.size(); i++) m[hand[i]]++;

        for(auto i: m){
            int number = i.first;
            int count = i.second;
            if(count > 0){
                for (int j = 0; j < groupSize; j++) {
                    if (m[number + j] < count) return false;
                    m[number + j] -= count;
                }
            }
        }
        return true;
    }
};

