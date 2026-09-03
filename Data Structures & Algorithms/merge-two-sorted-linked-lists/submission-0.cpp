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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        while(list1 && list2){
            int val;
            if(list1->val<list2->val){
                val = list1->val;
                list1=list1->next;
            }
            else {val = list2->val;
            list2 = list2->next;
            }
            ListNode* tmp = new ListNode(val);
            if(!head){
                head = tmp;
                tail = tmp;
            }
            else{
                tail->next = tmp;
                tail = tmp;
            }
        }
        while(list1){
            ListNode* tmp = new ListNode(list1->val);
            if(!head){
                head = tmp;
                tail = tmp;
            }
            else{
                tail->next = tmp;
                tail = tmp;
            }
            list1=list1->next;
        }
          while(list2){
            ListNode* tmp = new ListNode(list2->val);
            if(!head){
                head = tmp;
                tail = tmp;
            }
            else{
                tail->next = tmp;
                tail = tmp;
            }
            list2=list2->next;
        }
        return head;
    }
};
