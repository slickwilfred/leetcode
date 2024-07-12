/**
 * Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
 
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode* prev;
    ListNode() : val(0), next(nullptr), prev(nullptr){};
    ListNode(int x) : val(x), next(nullptr), prev(nullptr){};
    ListNode(int x, ListNode* next, ListNode* prev) : val(x), next(next), prev(prev){};
};

class Solution {
    public: 
        ListNode* reverseBetween(ListNode* head, int left, int right) {
            if (head == NULL || left == right) {
                return head;
            }

            ListNode dummy(0);
            dummy.next = head;
            ListNode* prev = &dummy;

            // move prev to left -1 node
            for (int i = 0; i < left - 1; i++) {
                prev = prev->next;
            }

            ListNode* curr = prev->next;
            ListNode* Next = nullptr;

            // traverse the list and modify links between nodes
            // curr is pointing at the left node and we'll iterate within the right bound
            for (int i = 0; i < right - left; i++) {
                Next = curr->next; // Next holds the next value in the list to be swapped
                curr->next = Next->next; // makes curr (bound head) equal the Nexts next value
                Next->next = prev->next; // makes Next's next value equal to original bound head
                prev->next = Next; // makes Next equal to the bound head (beginning of reversed nodes)
            }

            // return head
            return dummy.next;
        }
};