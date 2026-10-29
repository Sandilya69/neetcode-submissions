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
    ListNode* sortList(ListNode* head) {
        int length = 0;
        for (ListNode* node = head; node; node = node->next) length++;
        ListNode dummy(0);
        dummy.next = head;
        for (int width = 1; width < length; width *= 2) {
            ListNode* tail = &dummy;
            ListNode* current = dummy.next;
            while (current) {
                ListNode* left = current;
                int lc = 0;
                for (int i = 0; i < width && current; i++) {
                    lc++;
                    current = current->next;
                }
                ListNode* right = current;
                int rc = 0;
                for (int i = 0; i < width && current; i++) {
                    rc++;
                    current = current->next;
                }
                while (lc || rc) {
                    ListNode* chosen;
                    if (rc == 0 || (lc > 0 && left->val <= right->val)) {
                        chosen = left;
                        left = left->next;
                        lc--;
                    } else {
                        chosen = right;
                        right = right->next;
                        rc--;
                    }
                    tail->next = chosen;
                    tail = chosen;
                }
                tail->next = current;
            }
        }
        return dummy.next;
    }
};
