/**
 * You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.

Letters are case sensitive, so "a" is considered a different type of stone from "A".

 

Example 1:

Input: jewels = "aA", stones = "aAAbbbb"
Output: 3
Example 2:

Input: jewels = "z", stones = "ZZ"
Output: 0
 

Constraints:

1 <= jewels.length, stones.length <= 50
jewels and stones consist of only English letters.
All the characters of jewels are unique.
 */

#include <string>
#include <unordered_map>
using namespace std; 

class Solution {
    public:
        int numJewelsInStones(string jewels, string stones) {
            // map to store characters (stones) and their frequency
            unordered_map<char, int> map;
            for (char ch : stones) {
                    map[ch]++;
            }

            // get the frequency of the stones that are jewels and add to the count
            int count = 0;
            for (char ch : jewels) {
                if (map.find(ch) != map.end()){ 
                    count += map[ch];
                }
            }
            return count;
        }
};