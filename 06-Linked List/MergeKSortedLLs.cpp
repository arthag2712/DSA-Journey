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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> pq;
        for(int i=0;i<lists.size();i++)
            pq.push({lists[i]->val, lists[i]});
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(!pq.empty()){
            auto node = pq.top();
            temp->next = node.second;
            pq.pop();
            temp = temp->next;
            if((node.second)->next) 
                pq.push({(node.second)->next->val, (node.second)->next});
        }
        return dummy->next;
    }
};
