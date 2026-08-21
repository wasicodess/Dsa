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

            ListNode* KthNode = findKthNode(temp, k);

            if (KthNode == NULL) {
                if (prevNode != NULL)
                    prevNode->next = temp;

                break;
            }

            ListNode* nextNode = KthNode->next;

            KthNode->next = NULL;

            reverse(temp);

            if (temp == head) {
                head = KthNode;
            }
            else {
                prevNode->next = KthNode;
            }

            prevNode = temp;

            temp = nextNode;
        }

        return head;
    }
};