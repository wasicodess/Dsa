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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* tail=head;
        int size=1;
        if(tail==NULL || tail->next==NULL){
            return head;
        }
        while(tail->next!=NULL){
            tail=tail->next;
            size++;
        }
        tail->next=head;
        k=k%size;
       if(k==0){
         tail->next = NULL;
         return head;
        }
        int steps=size-k;
        for(int i =0;i<steps;i++){
            tail=tail->next;
        }
        ListNode* newhead=tail->next;
        tail->next=NULL;
        return newhead;
    }
};