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
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }

        ListNode* sublistHead = prev->next;
        ListNode* sublistTail = sublistHead;
        for (int i = 0; i < right - left; ++i) {
            sublistTail = sublistTail->next;
        }

        ListNode* nextNode = sublistTail->next;
        sublistTail->next = nullptr;
        prev->next = reverseList(sublistHead);
        sublistHead->next = nextNode;

        return dummy.next;
    }

private:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }
};