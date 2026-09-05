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
        if(!head)   return nullptr;
        unordered_map<Node*, Node*>mp;
        Node*tmp = head;
        Node* newHead = nullptr;
        Node* tail = nullptr;
        while(tmp){
            if(mp.find(tmp)==mp.end()){
                mp[tmp] = new Node(tmp->val);
            }
            if(tmp->random && mp.find(tmp->random)==mp.end()){
                mp[tmp->random] = new Node(tmp->random->val);
            }
            if(!newHead){
                newHead = mp[tmp];
                tail = newHead;
            }else{
                tail->next = mp[tmp];
                tail = mp[tmp];
            }
            mp[tmp]->random = mp[tmp->random];
            tmp = tmp->next;
        }
        return mp[head];
    }
};
