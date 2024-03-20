/**
 * @file 1456_MaximumNumVowels.cpp
 * @author Stanley Ezeh (ezeh.stanley.es@gmail.com)
 * @brief
 *
 * Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.



Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
Example 3:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.

 * @version 0.1
 * @date 2024-01-31
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    int maxVowels(string s, int k)
    {
        int i = 0, j = 0, n = s.length();
        int maxc = 0, count = 0;

        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};

        for (i = 0; i < n; i++)
        {
            // check and increase count
            if(vowels.find(s[i]) != vowels.end()){
                count++;
                printf("Found %c. Number of vowels now %d \n",s[i], count);
            } 
            if(i>=k-1){ // window size
                maxc = max(maxc, count);
                printf("Maxc =%d count =%d\n",maxc, count);
                if (vowels.find(s[j])!=vowels.end()){
                    count--;
                    printf("Reducing count of vowels in window to %d vowels \n", count);
                }
                j++;
                printf("shifting window j= %d \n", j);
            }
        }
        return maxc;
    }
};

int main()
{
    string str{"abciivdeaisf"};
    Solution s;
    cout << s.maxVowels(str, 3);

    return 0;
}