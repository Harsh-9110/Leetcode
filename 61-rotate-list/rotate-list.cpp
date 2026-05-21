/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next)
 *         : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (!head || !head->next || k == 0)
            return head;

        // find length and tail
        int len = 1;

        ListNode* tail = head;

        while (tail->next) {

            tail = tail->next;
            len++;
        }

        // reduce unnecessary rotations
        k = k % len;

        if (k == 0)
            return head;

        // make circular list
        tail->next = head;

        // find new tail
        int steps = len - k;

        ListNode* newTail = head;

        for (int i = 1; i < steps; i++) {

            newTail = newTail->next;
        }

        // new head
        ListNode* newHead =
            newTail->next;

        // break circle
        newTail->next = NULL;

        return newHead;
    }
};