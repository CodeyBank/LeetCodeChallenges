/**
 * @file 392_Is_Subsequence.cpp
 * @author Stanley Ezeh (ezeh.stanley.es@gmail.com)
 * @brief 
 * 
 Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original s
tring by deleting some (can be none) of the characters without disturbing the 
relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
 

Constraints:

0 <= s.length <= 100
0 <= t.length <= 104
s and t consist only of lowercase English letters.
 

Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k >= 109, 
and you want to check one by one to see if t has its subsequence. 
In this scenario, how would you change your code?
 * @version 0.1
 * @date 2024-01-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        // run through the list 
        int len_s = s.length();
        int len_t = t.length();

        int j=0;

        for(int i=0; i<len_t; ++i){
            if(s[j] == t[i]){
                j++;   
            }
        }

        return j==len_s;
        
    }
};


int main()
{

    string str = "abc", t = "ahbgdc";
    cout<<boolalpha;
    Solution s;
    cout<<s.isSubsequence(str, t);
    return 0;
}