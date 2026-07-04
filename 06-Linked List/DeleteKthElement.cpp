/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
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
    ListNode* deleteKthNode(ListNode* &head, int k) {
        if(head==NULL) return head;
        if(k==1){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        int count=0;
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp != NULL){
            count++;
            if(count==k){
                prev->next = prev->next->next;
                delete temp;
                return head;
            }
            prev=temp;
            temp=temp->next;
        }
        return head;
    }
};