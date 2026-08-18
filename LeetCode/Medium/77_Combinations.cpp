/**
 * Problem Link : https://leetcode.com/problems/combinations/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
vector<vector<int>> ans;
vector<int> curr;
void solve(int start, int n,int k){
    // if size 2 hai tabhi insert krenge 
    if(curr.size()==k){
        ans.push_back(curr);
        return ;
    }

    for(int i=start;i<=n;i++){
        curr.push_back(i);
        solve(i+1, n,k);
        curr.pop_back();
    }
}
    vector<vector<int>> combine(int n, int k) {
        solve(1, n, k);
        return ans;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
