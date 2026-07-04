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
        ListNode* insertBeforeX(ListNode* &head, int X, int val) {
            //your code goes here
            if(head->data == X){
                return new ListNode(val,head);
            }
            ListNode* temp = head;
            ListNode* prev = nullptr;
            while(temp != nullptr){
                if(temp->data == X){
                    ListNode* newNode = new ListNode(val, temp);
                    prev->next = newNode;
                    break;
                }
                prev=temp;
                temp = temp->next;
            }
            return head;

        }
};