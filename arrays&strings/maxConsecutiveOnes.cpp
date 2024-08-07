/*
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

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
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
0 <= k <= nums.length
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            // sliding window problem (l & r pointers)
            // initialize vars for max length and num of zeros
            int left = 0;
            int zeroes = 0;
            int maxLen = 0;

            for (int right = 0; right < nums.size(); right++){
                if (nums[right] == 0) {
                    zeroes++;
                }

                // while the count of zeroes is greater than k
                // move the left pointer and decrement the zero count if one is encountered
                while (zeroes > k) {
                    if (nums[left] == 0) {
                        zeroes--;
                    }
                    left++;
                }
                maxLen = max(maxLen, (right-left+1));

            }
            return maxLen;
            
        }

        void print(int length) {
            cout << "Max length: " << length << endl;
        }

};

int main() {
    Solution sol;
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    int max = sol.longestOnes(nums, k);
    sol.print(max);
}