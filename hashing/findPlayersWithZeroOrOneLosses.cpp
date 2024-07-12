/**
 * You are given an integer array matches where matches[i] = [winneri, loseri] indicates that the player winneri defeated player loseri in a match.

Return a list answer of size 2 where:

answer[0] is a list of all players that have not lost any matches.
answer[1] is a list of all players that have lost exactly one match.
The values in the two lists should be returned in increasing order.

Note:

You should only consider the players that have played at least one match.
The testcases will be generated such that no two matches will have the same outcome.
 

Example 1:

Input: matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
Output: [[1,2,10],[4,5,7,8]]
Explanation:
Players 1, 2, and 10 have not lost any matches.
Players 4, 5, 7, and 8 each have lost one match.
Players 3, 6, and 9 each have lost two matches.
Thus, answer[0] = [1,2,10] and answer[1] = [4,5,7,8].
Example 2:

Input: matches = [[2,3],[1,3],[5,4],[6,4]]
Output: [[1,2,5,6],[]]
Explanation:
Players 1, 2, 5, and 6 have not lost any matches.
Players 3 and 4 each have lost two matches.
Thus, answer[0] = [1,2,5,6] and answer[1] = [].
 

Constraints:

1 <= matches.length <= 105
matches[i].length == 2
1 <= winneri, loseri <= 105
winneri != loseri
All matches[i] are unique.
 */
#include <vector>
#include <iostream>
#include <set>

using namespace std;

class Solution {
    public:
        vector<vector<int>> findWinners(vector<vector<int>>& matches) {
            set<int> noLoss, oneLoss, multipleLosses;

            for (size_t i = 0; i < matches.size(); i++) {
                int winner = matches[i][0];
                int loser = matches[i][1];

                // Place winner
                // If winner is in oneLoss or losers sets, it can be ignored
                if (oneLoss.find(winner) == oneLoss.end() && multipleLosses.find(winner) == multipleLosses.end()) {
                    noLoss.insert(winner);
                }

                // place loser
                // if the loser has no losses, remove and add the loser to oneLoss
                // if the loser has one loss, remove and add the loser to mutipleLosses
                // if the loser isn't present in multipleLosses, add the loser to oneLoss
                if (noLoss.find(loser) != noLoss.end()) {
                    noLoss.erase(loser);
                    oneLoss.insert(loser);
                } else if (oneLoss.find(loser) != oneLoss.end()){
                    oneLoss.erase(loser);
                    multipleLosses.insert(loser);
                } else { 
                    if (multipleLosses.find(loser) == multipleLosses.end()) {
                        oneLoss.insert(loser);
                    } 
                }

            }
            
            vector<int> wins(noLoss.begin(), noLoss.end());
            vector<int> losses(oneLoss.begin(), oneLoss.end());

            return { wins, losses };
        }
};