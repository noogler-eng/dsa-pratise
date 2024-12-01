// https://leetcode.com/problems/identify-the-largest-outlier-in-an-array/description/

// (sum_of_number * 2) + outliers = total_sum
// [-2, -1, -3, -6, 4]

#include<iostream>
#include<unordered_map>
using namespace std;

// (2 * x) + y = total_sum
// y can be an outlier if there is another element x which twice and add can give totalSum
// y becomes outlier
// total_sum - 2 * a = y
int largest_outlier(vector<int> nums){
    unordered_map<int, int> m;
    int outlier = INT_MIN;
    int total_sum = 0;

    for (int i = 0; i < nums.size(); i++) {
        total_sum += nums[i];
        m[nums[i]]++;
    }

    for (int i = 0; i < nums.size(); i++) {
        // if a is nums[i] then
        int possibleOutlier = total_sum - (2 * nums[i]);
        if (m.find(possibleOutlier) != m.end()) {
            if (nums[i] == possibleOutlier && m[nums[i]] == 1)
                continue;
            outlier = max(outlier, possibleOutlier);
        }
    }

    return outlier;
}


int main(){
    vector<int> nums = {6,-31,50,-35,41,37,-42,13};
    cout<<largest_outlier(nums)<<endl;
    return 0;
}