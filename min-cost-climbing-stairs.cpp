#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // dp[i] is the min cost to reach step i (not step on it)
        // dp[0] = 0
        // dp[1] = 0
        // can arrive on i from i-1 or i-2
        // dp[i] = min(cost[i - 1] + dp[i - 1], cost[i - 2] + dp[i - 2])
        
        int sz = cost.size();

        vector<int> dp(sz + 1, 0);

        for (int i = 2 ; i <= sz ; i++){
            dp[i] = min(cost[i - 1] + dp[i - 1], cost[i - 2] + dp[i - 2]);
        }

        return dp[sz];
    }
};
