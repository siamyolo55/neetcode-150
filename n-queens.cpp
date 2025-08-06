#include<bits/stdc++.h>
using namespace std;

class Solution {
    set<int> rowVis;
    set<int> colVis;
    set<int> diagVisLeft;
    set<int> diagVisRight;
    vector<vector<string>> ans;

    bool isInvalidSpotForQueen(int r, int c){
        return rowVis.find(r) != rowVis.end() 
            || colVis.find(c) != colVis.end() 
            || diagVisRight.find(r + c) != diagVisRight.end() 
            || diagVisLeft.find(r - c) != diagVisLeft.end();
    }

    void dfs(int r, int &n, vector<string> &grid){
        if (r == n){
            ans.push_back(grid);
            return;
        }

        for (int c = 0 ; c < n ; c++){
            if (isInvalidSpotForQueen(r, c)){
                continue;
            }

            grid[r][c] = 'Q';
            rowVis.insert(r);
            colVis.insert(c);
            diagVisRight.insert(r + c);
            diagVisLeft.insert(r - c);

            dfs(r + 1, n, grid);

            grid[r][c] = '.';
            rowVis.erase(r);
            colVis.erase(c);
            diagVisRight.erase(r + c);
            diagVisLeft.erase(r - c);
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> grid(n, string(n, '.'));
        dfs(0, n, grid);

        return ans;
    }
};
