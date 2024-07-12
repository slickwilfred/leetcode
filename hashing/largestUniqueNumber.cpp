#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int largestUniqueNumber(vector<int>& nums) {
            unordered_map<int, int> map;
            int maxVal = -1;

            // store numbers and their frequency into a hashmap
            for (auto num : nums) {
                map[num]++;
            }

            // search for the largest number with a frequency of 1
            for (auto it = map.begin(); it != map.end(); it++){
                if (it->second == 1) {
                    maxVal = max(maxVal, it->first);
                }
            }
            return maxVal;
        }
};