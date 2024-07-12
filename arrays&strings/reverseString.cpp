/**
Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
 

Constraints:

1 <= s.length <= 105
s[i] is a printable ascii character.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public: 
    vector<char> reverseString(vector <char>& s) {
        int len = s.size()-1;
        for (int i = 0; i < len; i++) {
            char temp = s[i];
            s[i] = s[len];
            s[len] = temp;
            len--;
        }
        return s;
    }

    void print(vector <char> s) {
        cout << "Reversed array:" << endl;
        for (auto character : s) {
            cout << character;
        }
        cout << endl;
    }

};


int main() {
    Solution sol;
    vector <char> s = {'b', 'u', 's', 'i', 'n', 'e', 's', 's'};

    vector <char> prod = sol.reverseString(s);
    sol.print(s);

}