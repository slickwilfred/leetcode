/**
 * Given an integer array arr, count how many elements x there are, such that x + 1 is also in arr. If there are duplicates in arr, count them separately.

 

Example 1:

Input: arr = [1,2,3]
Output: 2
Explanation: 1 and 2 are counted cause 2 and 3 are in arr.
Example 2:

Input: arr = [1,1,3,3,5,5,7,7]
Output: 0
Explanation: No numbers are counted, cause there is no 2, 4, 6, or 8 in arr.
 

Constraints:

1 <= arr.length <= 1000
0 <= arr[i] <= 1000
 */
#include <vector>
#include <iostream>
#include <set>
using namespace std;

class Solution {
    public:
        int countElements(vector<int>& arr) {
            // create a set to hold the sequence of numbers
            set<int> sequence;
            int count = 0;
            for (auto num : arr) {
                sequence.insert(num);
            }

            // check if val + 1 is present in the set
            // if true, add to the count
            for (int val : arr) {
                if (sequence.find(val + 1) != sequence.end()){
                    count++;
                }
            }
            return count;
        }
};

