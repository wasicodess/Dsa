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
    ListNode* reverse(ListNode* head){
      ListNode* next=NULL;
      ListNode* prev=NULL;
      ListNode* curr=head;
      while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
      }  
      return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL || head==NULL){
            return true;
        }
        ListNode* fast= head;
        ListNode* slow=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newhead=reverse(slow->next);
        ListNode* first=head;
        ListNode* second=newhead;

        while(second!=NULL){
            if(first->val!=second->val){
                reverse(newhead);
                return false;
            }
            else{
                first=first->next;
                second=second->next;
            }
        }
        reverse(newhead);
        return true;
    }
};