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
    void reorderList(ListNode* head) {
        vector<ListNode*>arr;
        if(!head)   return;
        for(ListNode*tmp = head;tmp!=nullptr;tmp=tmp->next){
            arr.push_back(tmp);
        }
        int n = arr.size();
        int i;
        for(i=0;i<n/2;i++){
            arr[i]->next = arr[n-i-1];
            if(i+1<n){
                arr[n-i-1]->next = arr[i+1];
            }
            else{
                arr[n-i-1]->next = nullptr;
            }
        }
        arr[n/2]->next = nullptr;
    }
};
