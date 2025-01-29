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
        // Do the fast and slow pointers
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the 2nd linked list
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        ListNode* next = slow;

        while (curr != nullptr){
            next = curr->next;

            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Merge the forward and reversed lists!
        ListNode* reverse = prev;
        ListNode* headNext = head->next;
        ListNode* reverseNext = reverse->next;

        while (headNext != nullptr && reverseNext != nullptr){
            head->next = reverse;
            reverse->next = headNext;
            head = headNext;
            reverse = reverseNext;
            headNext = head->next;
            reverseNext = reverse->next;
        }
    }
};