class Solution {
public:

    ListNode* findKthNode(ListNode* temp, int k) {
        k--;

        while (temp != NULL && k > 0) {
            k--;
            temp = temp->next;
        }

        return temp;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        ListNode* prevNode = NULL;

        while (temp != NULL) {

            // Find kth node
            ListNode* KthNode = findKthNode(temp, k);

            // Less than k nodes remaining
            if (KthNode == NULL) {
                if (prevNode != NULL)
                    prevNode->next = temp;

                break;
            }

            // Save next group
            ListNode* nextNode = KthNode->next;

            // Disconnect current group
            KthNode->next = NULL;

            // Reverse current group
            reverse(temp);

            // First group
            if (temp == head) {
                head = KthNode;
            }
            else {
                prevNode->next = KthNode;
            }

            // temp is now the last node of reversed group
            prevNode = temp;

            // Move to next group
            temp = nextNode;
        }

        return head;
    }
};