/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {

        unordered_set<int> st(nums.begin(), nums.end());

        int components = 0;

        while (head) {

            if (st.count(head->val) &&
               (!head->next ||
                !st.count(head->next->val))) {

                components++;
            }

            head = head->next;
        }

        return components;
    }
};