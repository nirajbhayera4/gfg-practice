/**
 * Problem Link : https://leetcode.com/problems/palindrome-partitioning/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int n;
bool ispalindrome(string &s, int l ,int r){
    while(l <r){
        if(s[l]!=s[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}
void backtrack(string &s, int idx, vector<string> &curr, vector<vector<string>> &result){
    if(idx ==n){
        result.push_back(curr);
    }
    for(int i=idx;i <n;i++){
        if(ispalindrome(s, idx, i)){
            curr.push_back(s.substr(idx, i-idx+1));
            backtrack(s,i+1,curr,result);
            curr.pop_back();

        }
    }
}
    vector<vector<string>> partition(string s) {
        n=s.length();
        vector<vector<string>> result;
        vector<string> curr;

        backtrack(s, 0, curr, result);
        return result;


    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
