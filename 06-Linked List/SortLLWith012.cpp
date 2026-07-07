/*
Definition of singly linked list:
class ListNode{
  public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};
*/

class Solution {
    public:
        ListNode* sortList(ListNode* &head) {
            //your code goes here
            ListNode* zeroHead = new ListNode(-1);
            ListNode* oneHead = new ListNode(-1);
            ListNode* twoHead = new ListNode(-1);

            ListNode* zero = zeroHead;
            ListNode* one = oneHead;
            ListNode* two = twoHead;

            ListNode* temp = head;

            while(temp != nullptr){
                if(temp->data == 0){
                    zero->next = temp;
                    temp = temp->next;
                    zero = zero->next;
                }else if(temp->data == 1){
                    one->next = temp;
                    temp = temp->next;
                    one = one->next;
                }else{
                    two->next = temp;
                    temp = temp->next;
                    two = two->next;
                }
            }
            zero->next = (oneHead->next) ? (oneHead->next) : (twoHead->next);
            one->next = (twoHead->next);
            two->next = nullptr;

            ListNode* newHead = zeroHead->next;

            delete oneHead;
            delete twoHead;
            delete zeroHead;

            return newHead;
        };
};