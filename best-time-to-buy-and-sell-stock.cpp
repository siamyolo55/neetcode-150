#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l, r, maxP;

        l = r = maxP = 0;

        while (r < prices.size()) {
            if (prices[r] > prices[l])
                maxP = max(maxP, prices[r] - prices[l]);
            else 
                l = r;

            r++;
        }

        return maxP;
    }
};