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
    ListNode* reverseList(ListNode* head) {
        // vector<int> nums;
        // if(head == nullptr) return head;
        // ListNode* temp = head;
        // while(temp != NULL){
        //     nums.push_back(temp->val);
        //     temp = temp->next;
        // }
        // reverse(nums.begin(),nums.end());
        // ListNode* temp2 = head;
        // int index = 0;
        // while(temp2 != nullptr){
        //     temp2->val = nums[index++];
        //     temp2 = temp2->next;
        // }
        // return head;

        if(!head) return head;
        if(!head->next) return head;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nex;
        while(curr != nullptr){
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;

    }
};