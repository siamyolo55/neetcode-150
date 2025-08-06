#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> func(int curOpen, int curClose, int &n, string curStr){
        if (curOpen < curClose){
            return {};
        }

        if (curOpen == curClose && curStr.size() == 2 * n){
            return { curStr };
        }

        vector<string> partOne, partTwo;

        if (curOpen + 1 <= n){
            partOne = func(curOpen + 1, curClose, n, curStr + '(');
        }
        
        if (curClose + 1 <= n){
            partTwo = func(curOpen, curClose + 1, n, curStr + ')');
        }
        
        partOne.insert(partOne.end(), partTwo.begin(), partTwo.end());
        return partOne;
    }

    vector<string> generateParenthesis(int n) {
        return func(0, 0, n, "");
    }
};
