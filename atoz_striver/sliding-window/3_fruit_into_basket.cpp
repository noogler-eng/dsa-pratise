// Fruit Into Baskets
// QUESTION - https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1

#include<iostream>
#include<vector>
using namespace std;

// Input: arr[]= [2, 1, 2]
// Output: 3
// Explanation: We can pick one fruit from all three trees. Please note that the type of fruits is same in the 1st and 3rd baskets.

// first include the types
// if types > 2 then remove it until it becomes 2 
// count length at every steps
int totalFruits(vector<int> &arr) {
    int i=0, j=0;
    int max_length = 0;
    unordered_map<int, int> m;
    while(j < arr.size()){
        m[arr[j]] = j;
        while(m.size() > 2){
            m[arr[i]]++;
            if(m[arr[i]] == 0) m.erase(arr[i]);
            i++;
        }
        max_length = max(max_length, j-i+1);
        j++;
    }
    return max_length;
}