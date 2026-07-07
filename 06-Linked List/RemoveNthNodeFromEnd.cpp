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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*
        if(!head) return head;
        int count = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            count++;
            temp = temp->next;
        }
        if(n==count){
            if(head->next==nullptr) return nullptr;
            else return head->next;
        }
        if(n>count) return head;
        ListNode* temp2 = head;
        while((count-n-1)>0){
            temp2 = temp2->next;
            count--;
        }
        temp2->next = temp2->next->next;
        return head;
        */
        ListNode* fast = head;
        ListNode* slow = head;
        for(int i=0;i<n;i++){
            fast = fast->next;
        }
        if(fast==nullptr) return head->next;
        while(fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};