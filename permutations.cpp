#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> getAllPermutationsFromIndex(int k, int &n, vector<int> &nums){
        if (k == n - 1){
            return {{nums[k]}};
        }

        auto permsFromNextIndex = getAllPermutationsFromIndex(k + 1, n, nums);
        int permsLen = permsFromNextIndex.size();

        vector<vector<int>> allPerms;

        for (int i = 0 ; i < permsLen ; i++){
            vector<int> curPerm = permsFromNextIndex[i];
            int curPermLen = curPerm.size();

            for (int p = 0 ; p <= curPermLen ; p++){
                vector copyCurPerm = curPerm;
                copyCurPerm.insert(copyCurPerm.begin() + p, nums[k]);
                allPerms.push_back(copyCurPerm);
            }
        }

        return allPerms;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();

        return getAllPermutationsFromIndex(0, n, nums);
    }
};
