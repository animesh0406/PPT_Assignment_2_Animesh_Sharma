/*
Question 3
We define a harmonious array as an array where the difference between its maximum value
and its minimum value is exactly 1.

Given an integer array nums, return the length of its longest harmonious subsequence
among all its possible subsequences.

A subsequence of an array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.

Example 1:
Input: nums = [1,3,2,2,5,2,3,7]
Output: 5

Explanation: The longest harmonious subsequence is [3,2,2,2,3]
*/
#include<bits/stdc++.h>
using namespace std;
int harmonic(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int l = 0;
        int best = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == nums[l]) {
                continue;
            }
            while (l < i && nums[i] - nums[l] > 1) {
                l++;
            }
            if (nums[i] - nums[l] == 1) {
                best = max(best, i - l + 1);
            }
        }
        return best;
    }
int main(){
    
    vector<int> m={1,3,2,2,5,2,3,7};
    cout<<"The required ouput is "<<harmonic(m)<<endl;
    return 0;
}