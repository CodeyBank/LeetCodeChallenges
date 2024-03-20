/**
 * @file 1732_prefixsum.cpp
 * @author Stanley Ezeh (ezeh.stanley.es@gmail.com)
 * @brief 
 * 
 * There is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes. T
 * he biker starts his trip on point 0 with altitude equal 0.

You are given an integer array gain of length n where gain[i] is the net gain in altitude between
 points i​​​​​​ and i + 1 for all (0 <= i < n). Return the highest altitude of a point.

 

Example 1:

Input: gain = [-5,1,5,0,-7]
Output: 1
Explanation: The altitudes are [0,-5,-4,1,1,-6]. The highest is 1.
Example 2:

Input: gain = [-4,-3,-2,-1,4,3,2]
Output: 0
Explanation: The altitudes are [0,-4,-7,-9,-10,-6,-3,-1]. The highest is 0.
 * @version 0.1
 * @date 2024-02-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;


void printvec(vector<int>v){
    for(auto &val: v){
        cout<<" "<<val;
    }
    cout<<endl;
}

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int>prefix(n+1);
        int sum=0;
        prefix[0]=0;
        for(int i=0; i<n; i++){      
            sum+=gain[i];
            cout<<sum<<endl;
            prefix[i+1] = sum;

        }
        printvec(prefix);
        return *std::max_element(prefix.begin(), prefix.end());
    }
};

int main()
{
    Solution s;
    vector<int> val {-4,-3,-2,-1,4,3,2};
    cout<<s.largestAltitude(val);
    return 0;
}