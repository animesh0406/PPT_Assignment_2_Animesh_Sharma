/*
Question 8
You are given an integer array nums and an integer k.

In one operation, you can choose any index i where 0 <= i < nums.length and change nums[i] to nums[i] + x where x is an integer from the range [-k, k]. You can apply this operation at most once for each index i.

The score of nums is the difference between the maximum and minimum elements in nums.

Return the minimum score of nums after applying the mentioned operation at most once for each index in it.

Example 1:
Input: nums = [1], k = 0
Output: 0

Explanation: The score is max(nums) - min(nums) = 1 - 1 = 0
*/
#include<bits/stdc++.h>
using namespace std;
int score_of_nums(vector<int>& v ,int k){
    
int mx=*max_element(v.begin(),v.end());
        int mn=*min_element(v.begin(),v.end());

        return max(0,mx-k-mn-k);
}
int main(){
   vector<int> v={1,3,6};
   cout<<"The Array is"<<endl;
   for(int i=0;i<v.size();i++){
    cout<<v[i]<<" ";
   }
   cout<<endl;
   cout<<"The score is "<<score_of_nums(v,3)<<endl;
   return 0; 
}