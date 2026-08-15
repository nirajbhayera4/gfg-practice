/**
 * Problem Link : https://leetcode.com/problems/fair-distribution-of-cookies/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int ans=INT_MAX;
void backtrack(vector<int> &cookies, int idx, vector<int>& child, int k){
    // all cookies distribute 

    if(idx==cookies.size()){
        int unfairness=*max_element(child.begin(), child.end());
        ans=min(ans,unfairness);
        return ;
    }
    // give current cookies to every possible child 
    for(int i=0;i<k;i++){
        child[i]+=cookies[idx];
        backtrack(cookies,idx+1,child,k);
        // undo backtrack
        child[i]-=cookies[idx];

    }


}
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>child(k,0);
        backtrack(cookies,0,child,k);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
