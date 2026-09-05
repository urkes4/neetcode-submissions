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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* tmp1, *tmp2;
        tmp1 = l1;
        tmp2 = l2;
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        while(tmp1 || tmp2 || carry){
            int num1, num2;
            num1 = (tmp1?tmp1->val:0);
            num2 = (tmp2?tmp2->val:0);
            int val = num1+num2+carry;
            carry = val/10;
            ListNode* tmp = new ListNode(val%10);
            if(!head){
                head = tail = tmp;
            }
            else{
                tail->next = tmp;
                tail = tmp;
            }
            if(tmp1)
                tmp1 = tmp1->next;
            if(tmp2)
                tmp2 = tmp2->next;
        }
        return head;
    }
};
