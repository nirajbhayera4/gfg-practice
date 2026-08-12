/**
 * Problem Link : https://leetcode.com/problems/fruits-into-baskets-iii/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
void build(int i, int l ,int r, vector<int> &seg, vector<int> &baskets)
{
    if(l==r){
        seg[i]=baskets[l];
        return ;

    }

    int mid=l + (r-l)/2;
    build(2*i+1,l,mid,seg,baskets);
    build(2*i+2,mid+1,r,seg,baskets);
    seg[i]=max(seg[2*i+1], seg[2*i+2]);
}
int query(int i, int l, int r, vector<int> &seg,int fruit){
    if(seg[i] < fruit){
        return false;
    }
    if(l==r){
        seg[i]=-1;
        return true;
    }
    bool placed=false;

    int mid= l+(r-l)/2;
    if(seg[2*i+1] >=fruit){
        placed=query(2*i+1,l,mid,seg,fruit);
    }
    else
    {
        placed=query(2*i+2,mid+1,r,seg,fruit);
    
    }
    seg[i]=max(seg[2*i+1], seg[2*i+2]);
    return placed;
}
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        vector<int> seg(4*n,-1);
        build(0,0,n-1,seg,baskets);
        int unplaced=0;

        for(int & fruit : fruits){
            if(query(0,0,n-1,seg,fruit)==false){
                unplaced++;
            }
        }
        return unplaced;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
