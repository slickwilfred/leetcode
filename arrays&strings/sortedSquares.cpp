/*
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.

*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public:
        vector<int> sortedSquares(vector<int> &nums) {
            int len = nums.size();
            vector<int> result(len);
            int left = 0;
            int right = len - 1;
            int pos = len - 1;

            // square values
            // if the left square is larger, add it to result and increment the left pointer
            // if the right square is larger, add it to result and decerment the right pointer
            while (left <= right) {
                int leftSq = nums[left] * nums[left];
                int rightSq = nums[right] * nums[right];

                if (leftSq > rightSq) {
                    result[pos] = leftSq;
                    left++;
                } else {
                    result[pos] = rightSq;
                    right--;
                }
                pos--;

            }
            return result;
        }

        void print(vector<int> result) {
            cout << "Sorted squares: " << endl;
            for (auto num : result) {
                cout << num << ", ";
            }
            cout << endl;
        }
};

int main() {
    Solution sol;
    vector<int> nums = {-8, -3, -1, 2, 6, 10};
    vector<int> sortedSq = sol.sortedSquares(nums);

    sol.print(sortedSq);
}