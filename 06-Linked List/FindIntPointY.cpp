/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempa = headA;
        ListNode* tempb = headB;
        while (tempa != tempb) {
            if (tempa == nullptr)
                tempa = headB;
            else
                tempa = tempa->next;

            if (tempb == nullptr)
                tempb = headA;
            else
                tempb = tempb->next;
        }
        return tempa;
    }
};