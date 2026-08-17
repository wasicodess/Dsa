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
    ListNode* middleNode(ListNode* head) {
        //my first approach 
        // ListNode* temp=head;
        // int count=0;
        // int size=0;
        // while(temp!=NULL){
        //     temp=temp->next;
        //     count++;
        // }
        // // if(count%2==0) size=(count/2)+1;
        // // else size=count/2;
        // temp=head;

        // for(int i=0;i<count/2;i++){
        //     temp=temp->next;
        // }
        // return temp;

        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};