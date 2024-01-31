/**
 * @file 1071_GreatestCommonDivisor.cpp
 * @author Stanley Ezeh (ezeh.stanley.es@gmail.com)
 * @brief 
 * 
 * For two strings s and t, we say "t divides s" if and only if s = t + ... + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

 

Example 1:

Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
Example 2:

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
Example 3:

Input: str1 = "LEET", str2 = "CODE"
Output: ""
 * 
 * @version 0.1
 * @date 2024-01-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // first is to confirm if the string str2 is contained in str1
        // A faster aproach is to check if str1 + str2 == str2 +str1. 
        // if true, then str2 is contained in str1
        // then we find the greatest common divisor of str2's length and str1's length
        // this will be the number of characters we need to  return

        string ret;
        int gcd=0;
        if((str1+str2) ==(str2+str1)){ // str2 is contained in str1
           gcd =  __gcd(str1.length(), str2.length());
           ret = str1.substr(0, gcd);
        }

        return ret;
    }
};


int main()
{
    string str1 = "ABCDABCD", str2 = "ABCD";
    Solution s;
    cout<<s.gcdOfStrings(str1, str2);
    
    return 0;
}