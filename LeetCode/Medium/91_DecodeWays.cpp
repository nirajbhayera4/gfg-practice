/**
 * Problem Link : https://leetcode.com/problems/decode-ways/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int t[101];
int solve(int i, string &s, int &n){
    if(t[i]!=-1){
        return t[i];

    }
    if(i==n){
        return t[i]=1;
    }
    if(s[i]=='0'){
        return t[i]=0;
    }
    int result=solve(i+1,s,n);
    if(i +1<n){
        if(s[i]=='1' || s[i]=='2' && s[i+1]<='6'){
            result+=solve(i+2, s, n);
        }
    }
    return t[i]=result;

}
    int numDecodings(string s) {
        int n=s.size();
        memset(t,-1,sizeof(t));
        return solve(0,s,n);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
