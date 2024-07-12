#include <string>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) {
            unordered_map<char, int> mag;

            // add all characters of magazine into a map
            for (int i = 0; i < magazine.length(); i++) {
                mag[magazine[i]]++;
            }

            // return false if the character isn't found or the frequency of the character is 0
            for (auto ch : ransomNote) {
                auto it = mag.find(ch);

                if (it == mag.end() || it->second == 0) {
                    return false;
                }

                it->second--;
            }

            return true;

            
        }
};