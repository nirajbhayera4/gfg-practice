/**
 * Problem Link : https://leetcode.com/problems/find-the-least-frequent-digit/
 * Platform     : LeetCode
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLeastFrequentDigit(int n) {
        int hash[10]={0};

        int temp=n,freq=10,ans=0;

        while(temp >0){
            hash[temp % 10]++;
            temp/=10;
        }

        for(int i=9;i>=0;i--){
            if(hash[i]==0)continue;
            else{
                if(hash[i]<=freq){
                    freq=hash[i];
                    ans=i;
                }
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
