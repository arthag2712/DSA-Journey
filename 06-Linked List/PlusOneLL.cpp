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
    ListNode(int val1)
    {
        val = val1;
        next = NULL;
    }
    ListNode(int val1, ListNode *next1)
    {
        val = val1;
        next = next1;
    }
};
*/

class Solution {
public:
    ListNode* reverse(ListNode* head) {
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
    ListNode *addOne(ListNode *head) {
        ListNode* temp = reverse(head);
        ListNode* temp1 = temp;
        while(temp->next && temp->val == 9){
            temp->val = 0;
            temp = temp->next;
        }
        if(temp->val == 9) {
            temp->val = 0;
            ListNode* newNode = new ListNode(1);
            temp->next = newNode;
        }else{
            temp->val = temp->val + 1;
        }
        return reverse(temp1);
    }
};