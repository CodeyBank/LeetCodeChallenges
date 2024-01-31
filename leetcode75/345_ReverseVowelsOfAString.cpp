/**
 * @file 345_ReverseVowelsOfAString.cpp
 * @author Stanley Ezeh (ezeh.stanley.es@gmail.com)
 * @brief 
 * 
 * Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 

Example 1:

Input: s = "hello"
Output: "holle"
Example 2:

Input: s = "leetcode"
Output: "leotcede"
 

Constraints:

1 <= s.length <= 3 * 105
s consist of printable ASCII characters.
 * @version 0.1
 * @date 2024-01-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<unordered_set>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int left = 0, right = s.length() - 1;

        while (left < right) {
            while (left < right && vowels.find(tolower(s[left])) == vowels.end()) {
                left++;
            }
            while (left < right && vowels.find(tolower(s[right])) == vowels.end()) {
                right--;
            }

            swap(s[left], s[right]);
            left++;
            right--;
        }

        return s;
    }
};

int main()
{
    
    return 0;
}