#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        int findMaxLength(vector<int>& nums) {
            unordered_map<int, int> map;
            int count = 0;
            int maxLen = 0;

            // insert count of 0 at index -1
            map[0] = -1;

            // add 0's and 1's to the count to find valid lengths
            for (int i = 0; i < nums.size(); i++) {
                count = count + (nums[i] == 1 ? 1 : -1);

                // check if the count is present in the map
                // if it is, compare max values
                // if not, insert 
                if (map.find(count) != map.end()) {
                    maxLen = max(maxLen, i - map[count]);
                } else {
                    map[count] = i;
                }
            }
            return maxLen;
        }
};
