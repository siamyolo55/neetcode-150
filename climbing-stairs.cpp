class Solution {
public:
    int climbStairs(int n) {
        // define dp[i]
        // dp[i] is the total number of ways you can reach i'th step with 1 or 2 steps at a time
        // you can reach i'th step from either i-1'th or i-2'th step
        // so dp[i] = dp[i-1] + dp[i-2]
        // dp[0] = 1, since you're already on the ground
        // dp[1] = 1, take 1 step.
        // dp[2] = 1 + 1

        int dp[n + 1];
        
        dp[0] = dp[1] = 1;

        for (int i = 2 ; i <= n ; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};
