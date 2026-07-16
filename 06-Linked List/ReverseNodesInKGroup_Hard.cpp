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
    ListNode* reverseLL(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* getKthNode(ListNode* temp, int k) {
        k--;

        while (temp && k--) {
            temp = temp->next;
        }

        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        ListNode* prevGroupTail = nullptr;

        while (temp) {

            ListNode* kthNode = getKthNode(temp, k);

            // Less than k nodes remain
            if (!kthNode) {
                if (prevGroupTail)
                    prevGroupTail->next = temp;
                break;
            }

            ListNode* nextGroupHead = kthNode->next;

            // Detach current group
            kthNode->next = nullptr;

            // Reverse current group
            ListNode* newHead = reverseLL(temp);

            // Connect previous group
            if (!prevGroupTail)
                head = newHead;
            else
                prevGroupTail->next = newHead;

            // temp is now the tail of the reversed group
            temp->next = nextGroupHead;

            // Move pointers for next iteration
            prevGroupTail = temp;
            temp = nextGroupHead;
        }

        return head;
    }
};