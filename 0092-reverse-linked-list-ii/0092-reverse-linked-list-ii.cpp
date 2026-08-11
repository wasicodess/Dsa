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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (head == NULL || left == right)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // prev will reach the node BEFORE left
        ListNode* prev = dummy;

        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // temp is the first node we want to reverse
        ListNode* temp = prev->next;

        // Reverse the required portion
        for (int i = 0; i < right - left; i++) {

            ListNode* next = temp->next;

            temp->next = next->next;

            next->next = prev->next;

            prev->next = next;
        }

        return dummy->next;
    }
};