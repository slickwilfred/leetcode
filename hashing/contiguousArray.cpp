#include <vector>
#include <map>
using namespace std;

class Solution {
    public:
        int findMaxLength(vector<int>& nums) {
            map<int, int> map;
            int count = 0;
            int maxLen = 0;

            // insert count of 0 at index -1
            map.insert({ 0, -1 });

            // add 0's and 1's to the count to find valid lengths
            for (int i = 0; i < nums.size(); i++) {
                count = count + (nums[i] == 1 ? 1 : -1);

                // check if the count is present in the map
                // if it is, compare max values
                // if not, insert 
                auto it = map.find(count);
                if (it != map.end()) {
                    maxLen = max(maxLen, i - it->first);
                } else {
                    map.insert(count, i);
                }
            }
            return maxLen;
           
        }
};