/**
 * @file 334_IncreasingTripletSubsequence.cpp
 * @author Stanley Ezeh (ezeh.stanley.es@gmail.com)
 * @brief 
 * 
 * Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

 

Example 1:

Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.
Example 2:

Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.
Example 3:

Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.
 * @version 0.1
 * @date 2024-01-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include <vector>
#include <stdio.h>
using namespace std;


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
   int c1 = INT_MAX, c2 = INT_MAX;
    for (int x : nums) {
        if (x <= c1) {
            c1 = x;           // c1 is min seen so far (it's a candidate for 1st element)
        } else if (x <= c2) { // here when x > c1, i.e. x might be either c2 or c3
            c2 = x;           // x is better than the current c2, store it
        } else {              // here when we have/had c1 < c2 already and x > c2
            return true;      // the increasing subsequence of 3 elements exists
        }
    }
    return false;
    }
};

/**
 * Idea behind this: Control structure for an if else statment. c1 and c2 holds two different values. If x< c1, we update c1. if x is now 
 * bigger than c1, then we assign it to a second highest value and if it is higher than c1 and c2 then we have got three consecutive values
 * that are greater than each other
 */

int main()
{
    Solution s;
    std::cout<<boolalpha;
    std::vector<int> nums = {20,100,10,12,5,13};
    std::cout << (s.increasingTriplet(nums) ? "True" : "False") << std::endl;
    return 0;
    return 0;
}