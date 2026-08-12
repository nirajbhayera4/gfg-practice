/**
 * Problem Link : https://leetcode.com/problems/fruits-into-baskets-ii/
 * Platform     : LeetCode
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int unplaced=0;
        
        for(int i=0;i<n;i++){
            bool placed=false;
            for(int j=0;j<n;j++){
                if(fruits[i] <=baskets[j]){
                    placed=true;
                    baskets[j]=-1;
                    break;
                }
            }
            if(!placed){
                unplaced++;
            }
        }
        return unplaced;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
