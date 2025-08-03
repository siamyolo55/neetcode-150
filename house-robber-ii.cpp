#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int robRange(vector<int> & houses, int l, int r){
        const int LEN = houses.size() - 1;
        vector<int> dp(LEN + 1, 0);
        if (LEN == 0)
            return 0;
            
        if (LEN == 1)
            return houses[1];

        for (int i = 2 ; i <= LEN ; i++){
            dp[i] =  max(houses[i] + dp[i - 2], dp[i - 1]);
        }

        return dp[LEN];
    }

    int rob(vector<int>& nums) {
        // this is the same as solving house-robber for max(rob[1 .. n - 1], rob[2 .. n])
        const int N = nums.size();
        vector<int> houses(N + 1);
        std::copy(nums.begin(), nums.end(), houses.begin() + 1);

        return max(robRange(houses, 1, N - 1), robRange(houses, 2, N)); 
    }
};
