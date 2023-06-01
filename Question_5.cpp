/*
Question 5
Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

Example 1:
Input: nums = [1,2,3]
Output: 6
*/
#include <bits/stdc++.h>
using namespace std;
int maxProduct(vector<int> &nums){
    sort(nums.begin(), nums.end());
    return nums[nums.size()-1]*nums[nums.size()-2];
}
int main(){
    vector<int> n={2,4,3,6,3,8,10,34,23,9};
    cout<<"Given array is "<<endl;
    for(int i=0; i<n.size(); i++){
        cout<<n[i]<<" ";
    }
    cout<<endl<<"The maximum product is "<< maxProduct(n)<<endl;

}
//Time complexity is O(nlogn)