/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:

    Node* flattenDFS(Node* head) {

        Node* curr = head;
        Node* last = head;

        while (curr) {

            Node* next = curr->next;

            if (curr->child) {

                Node* childHead = curr->child;
                Node* childTail = flattenDFS(childHead);

                curr->next = childHead;
                childHead->prev = curr;

                curr->child = nullptr;

                if (next) {
                    childTail->next = next;
                    next->prev = childTail;
                }

                last = childTail;
            }
            else {
                last = curr;
            }

            curr = next;
        }

        return last;
    }

    Node* flatten(Node* head) {

        if (!head) return nullptr;

        flattenDFS(head);

        return head;
    }
};