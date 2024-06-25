/*
You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
Example 2:

Input: nums = [5], k = 1
Output: 5.00000
 

Constraints:

n == nums.length
1 <= k <= n <= 105
-104 <= nums[i] <= 104
*/


#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
    public:
        double fixMaxAverage(vector<int> &nums, int k) {
            int left = 0;
            double sum = 0;

            // Initialize the first window and its sum 
            for (int i = 0; i < k; i++){
                sum += nums[i];
            }

            // Set maxAvg
            double maxAvg = sum / k;

            // Iterate through the vector
            // Use max to determine the largest sub array
            for (int right = k; right < nums.size(); right++) {
                sum += nums[right] - nums[left];
                left++;

                maxAvg = max(maxAvg, (sum / k));
            }
            return maxAvg;
        }

        void print (double maxAvg) {
            cout << "The max average is: " << maxAvg << endl;
        }
};

int main() {
    Solution sol;
    vector<int> nums = {1,12,-5,-6,50,3};
    double ans = sol.fixMaxAverage(nums, 4);
    sol.print(ans);

}