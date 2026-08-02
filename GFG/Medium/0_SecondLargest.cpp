/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/second-largest3735/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int largest=INT_MIN;
        int secondlargest=INT_MIN;
        
        for(int num: arr){
            if(num > largest){
                secondlargest=largest;
                largest=num;
            }
            else if(num <largest && num > secondlargest){
                secondlargest=num;
            }
        }
        return (secondlargest ==INT_MIN)? -1: secondlargest;
    }
};
