/**
 * Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,1,2]
Output: [1,2]
Example 2:


Input: head = [1,1,2,3,3]
Output: [1,2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
 */


struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){};
    ListNode(int x) : val(x), next(nullptr){};
    ListNode(int x, ListNode* next) : val(x), next(next){};
};

class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            // base case
            // ensure head and head->next aren't null
            if (head == nullptr || head->next == nullptr) {
                return head;
            }

            // init curr node to point to the same node as head
            // head will be unchanged and will be used to return the result
            ListNode* curr = head;

            // traverse the list
            // if the next node's value is equal to the current, skip it (delete)
            // else: move to the next node
            while (curr != nullptr && curr->next != nullptr) {
                if (curr->val == curr->next->val) {
                    curr->next = curr->next->next;
                } else {
                    curr = curr->next;
                }
            }
            return head;
        }
};