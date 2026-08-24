/**
 * Problem Link : https://leetcode.com/problems/sort-the-people/
 * Platform     : LeetCode
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>>people;
        for(int i=0;i<names.size();i++){
            people.push_back({heights[i], names[i]});
        }

        // sort
        sort(people.begin(), people.end(), [](auto &a, auto &b){
            return a.first > b.first;
        });

        vector<string> ans;
        for(auto &p : people){
            ans.push_back(p.second);
        }
        return ans;
            
        
    }
    
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
