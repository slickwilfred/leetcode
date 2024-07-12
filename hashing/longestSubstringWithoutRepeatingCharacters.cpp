/**
 * Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
 */
#include <string>
#include <algorithm>
#include <set>

using namespace std; 

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            // sliding window solution (l & r pointers)
            int maxLength = 0;
            int left = 0;
            set<char> chars;

            for (int right = 0; right < s.length(); right++) {
                // while a duplicate character exists, delete characters from the left side of the set
                while(chars.find(s[right]) != chars.end()) {
                    chars.erase(s[left]);
                    left++;
                }
                // insert characters and determine the max length from the distance of left and right pointers
                chars.insert(s[right]);
                maxLength = max(maxLength, right - left + 1);
            }
            return maxLength;
        }
};