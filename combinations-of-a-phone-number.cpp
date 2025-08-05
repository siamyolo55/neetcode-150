#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<char, vector<char>> mp {
        {'2', vector<char> {'a', 'b', 'c'}},
        {'3', vector<char> {'d', 'e', 'f'}},
        {'4', vector<char> {'g', 'h', 'i'}},
        {'5', vector<char> {'j', 'k', 'l'}},
        {'6', vector<char> {'m', 'n', 'o'}},
        {'7', vector<char> {'p', 'q', 'r', 's'}},
        {'8', vector<char> {'t', 'u', 'v'}},
        {'9', vector<char> {'w', 'x', 'y', 'z'}}
    };

    void dfs(int curNumIdx, string builtCombination, string &nums, vector<string> &foundCombinations){
        if (builtCombination.size() == nums.size()){
            foundCombinations.push_back(builtCombination);
            return;
        }

        vector<char> letters = mp[nums[curNumIdx]];

        for (int i = 0 ; i < letters.size() ; i++){
            string newBuiltCombination = builtCombination + letters[i];
            dfs(curNumIdx + 1, newBuiltCombination, nums, foundCombinations);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        if (digits.empty())
            return ans;

        dfs(0, "", digits, ans);
        return ans;
    }
};
