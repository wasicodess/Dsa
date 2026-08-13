class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Step 1: Find length
        int count = 0;
        ListNode* temp = head;

        while(temp != NULL) {
            count++;
            temp = temp->next;
        }

        // Step 2: If we have to remove head
        if(count == n) {
            ListNode* curr = head;
            head = head->next;
            delete curr;
            return head;
        }

        // Step 3: Reach node BEFORE the node to delete
        temp = head;

        for(int i = 1; i < count - n; i++) {
            temp = temp->next;
        }

        // Step 4: Delete temp->next
        ListNode* curr = temp->next;
        temp->next = curr->next;
        delete curr;

        return head;
    }
};