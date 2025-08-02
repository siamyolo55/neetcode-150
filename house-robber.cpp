#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        // build dp[i]
        // dp[i] means the most money we can make by reaching (not entering) i'th house
        // either we take the home in i'th place or we don't
        // dp[i] =  max(nums[i] + dp[i - 2], dp[i - 1])
        // [2, 9, 8, 3, 6]
        // dp[1] = 2
        // dp[2] = max(nums[1], nums[2]) = 9
        // dp[3] = max(8 + 2, 9)         = 10
        // dp[4] = max(3 + 9, 10)        = 12
        // dp[5] = max(6 + 10, 12)       = 16

        int length = nums.size();

        vector<int> houses(length + 1);
        copy(nums.begin(), nums.end(), houses.begin() + 1);

        vector<int> dp(length + 1, 0);
        dp[1] = houses[1];

        for (int i = 2 ; i <= length ; i++){
            dp[i] =  max(houses[i] + dp[i - 2], dp[i - 1]);
        }

        return dp[length];
    }
};
