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
        if(!head)   return nullptr;
        ListNode* first, *second;
        first = head;
        int i;
        for(i=0;i<n;i++){
            first = first->next;
        }
        ListNode*prev = nullptr;
        second = head;
        while(first){
            prev = second;
            second=second->next;
            first = first->next;
        }
        if(prev){
            prev->next = second->next;
        }
        else{
            head = second->next;
        }
        return head;
    }
};
