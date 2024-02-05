/**
 * @file 1004_MaxConsecutiveOnes.cpp
 * @author Stanley Ezeh (ezeh.stanley.es@gmail.com)
 * @brief
 *
 *      ios_base::sync_with_stdio(false);
        cin.tie(NULL);

    Given a binary array nums and an integer k, return the
    maximum number of consecutive 1's in the array if you can flip at most k 0's.



Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 * @version 0.1
 * @date 2024-01-31
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// class Solution
// {
// public:
//     int longestOnes(vector<int> &nums, int k)
//     {
//         int i = 0, j = 0, count = 0, maxc = 0, n = nums.size();
//         int flipcount = k;
//         queue<int> loc;

//         for (i = 0; i < n; ++i)
//         {
//             // check for a 1
//             if (nums[i] == 1)
//             {
//                 count++;
//             }
//             else if (nums[i] ==0 && flipcount >0)
//             {
//                 loc.push(i); // we found a 0 here
//                 count++;
//                 printf("found a %d but flip=%d < k=%d\n", nums[i], flipcount, k);
//                 // nums[i] = 1;
//                 flipcount--;
//             }
//             else
//             {
//                 maxc = max(maxc, (i-j+1));
//                 // we have exhausted our flips
//                 j = loc.front() + 1;
//                 loc.pop();
//                 printf("J now shifted to %d\n", j);

//             }
//         }
//         return maxc;
//     }
    
// };

class Solution2{
    public:
    int longestOnes(vector<int> &nums, int k){
        int i = 0, j = 0, count = 0, maxc = 0, n = nums.size();
        int flipcount = k; 
        for(i=0; i<n; i++){
            if(nums[i] == 0){
                count++;
            }

            while (count>k){
                if(nums[j] == 0){
                    count--;
                }
                j++;
            }
            maxc = max(maxc, (i-j+1));
        }
        return maxc;
    }
};


int main()
{
    // vector<int> nums{0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    vector<int> nums{1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    Solution2 s;
    cout << s.longestOnes(nums, 2);
    return 0;
}