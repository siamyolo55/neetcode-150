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

    void dfs(int r, int c, int count, int &n, vector<string> &grid){
        if (count == n){
            // base case
            ans.push_back(grid);
            return;
        }

        if (r == n){
            return;
        }

        if (c == n){
            return;
        }

        if (isInvalidSpotForQueen(r, c)){
            dfs(r, c + 1, count, n, grid);
            return;
        }
        
        grid[r][c] = 'Q';
        rowVis.insert(r);
        colVis.insert(c);
        diagVisRight.insert(r + c);
        diagVisLeft.insert(r - c);
        count++;

        dfs(r + 1, 0, count, n, grid);

        grid[r][c] = '.';
        rowVis.erase(r);
        colVis.erase(c);
        diagVisRight.erase(r + c);
        diagVisLeft.erase(r - c);
        count--;

        dfs(r, c + 1, count, n, grid);
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> grid(n, string(n, '.'));

        dfs(0, 0, 0, n, grid);

        return ans;
    }
};
