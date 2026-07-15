/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        /*
        unordered_map <Node*, Node*> mp;
        Node* temp = head;
        while(temp){//creates a deep copy of the values
            Node* newNode = new Node(temp->val);
            mp[temp] = newNode;
            temp = temp->next;
        }
        temp = head;
        while(temp){
            Node* copyNode = mp[temp];
            copyNode->next = mp[temp->next];
            copyNode->random = mp[temp->random];
            temp = temp->next;
        }
        return mp[head];
        */

        //OPTIMAL SOLN
        Node* temp = head;
        while(temp){ //place new nodes just to the right of their original ones
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }
        //now place the random pointers
        temp = head;
        while(temp){
            if(temp->random) temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
        Node* copy = new Node(-1);
        Node* dummy = copy;
        temp = head;
        while(temp){
            dummy->next = temp->next;
            temp->next = temp->next->next;
            dummy = dummy->next;
            temp = temp->next;
        }
        return copy->next;
    }
};
