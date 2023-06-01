/*
Question 2
Alice has n candies, where the ith candy is of type candyType[i]. Alice noticed that she started to gain weight, so she visited a doctor. 

The doctor advised Alice to only eat n / 2 of the candies she has (n is always even). Alice likes her candies very much, and she wants to eat the maximum number of different types of candies while still following the doctor's advice. 

Given the integer array candyType of length n, return the maximum number of different types of candies she can eat if she only eats n / 2 of them.

Example 1:
Input: candyType = [1,1,2,2,3,3]
Output: 3

Explanation: Alice can only eat 6 / 2 = 3 candies. Since there are only 3 types, she can eat one of each type.*/
#include<bits/stdc++.h>
using namespace std;
int Candies(vector<int>& candyType) {
        unordered_map<int,int> M;
        for (int i = 0; i<candyType.size(); i++)
    {
        if (M.find(candyType[i]) == M.end())
        {
            M.insert(make_pair(candyType[i], 1));
        }
 
        // Else update the frequency
        else
        {
            M[candyType[i]]++;
        }

    }
     int distinct=M.size();
     int maxi=candyType.size()/2;
     if(distinct<maxi){
        return distinct;
     }
     return maxi;
}
//Time complexity in O(n) since iterated the array only once .

int main(){
    vector<int>candyType = {1,1,2,2,3,3};
    cout<<"Maximum distinct candies that she can eat is "<<Candies(candyType);
    return 0;
}